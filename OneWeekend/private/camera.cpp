#include "../public/camera.h"

camera::camera(int image_width, int image_height) 
{
    const double aspect_ratio = double(image_width) / image_height;
    const double viewport_height = 2.0;
    const double viewport_width = aspect_ratio * viewport_height;
    const double focal_length = 1.0;

    origin = vec3(0.0, 0.0, 0.0);
    
    w = unit_vector(vec3(0, 0, 1));  // 朝向z
    u = unit_vector(vec3(1, 0, 0));  // x 轴
    v = cross(w, u);                 // y 轴
    
    horizontal = viewport_width * u;
    vertical = viewport_height * v;
    
    lower_left_corner = origin - horizontal/2 - vertical/2 - focal_length * w;
    
    lens_radius = 0.0;  // 景深暂时设为0
}

// 完整参数的摄像机构造函数
camera::camera(
    vec3 lookfrom, vec3 lookat, vec3 vup,
    double vfov, double aspect_ratio, double aperture, double focus_dist
) {
    origin = lookfrom;
    lens_radius = aperture / 2;

    // 计算视口大小
    auto theta = degrees_to_radians(vfov);
    auto half_height = tan(theta/2);
    auto half_width = aspect_ratio * half_height;

    // 构建相机坐标系 (u, v, w)
    w = unit_vector(lookfrom - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    // 计算屏幕左下角位置
    lower_left_corner = origin
         - half_width * focus_dist * u
         - half_height * focus_dist * v
         - focus_dist * w;

    // 计算水平和垂直向量
    horizontal = 2*half_width*focus_dist*u;
    vertical = 2*half_height*focus_dist*v;
}

ray camera::get_ray(double s, double t) 
{
    vec3 rd = lens_radius * random_in_unit_disk();
    vec3 offset = u * rd.x() + v * rd.y();

    return ray(
        origin + offset,
        lower_left_corner + s*horizontal + t*vertical - origin - offset
    );
}
