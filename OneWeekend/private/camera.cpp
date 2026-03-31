#include"../public/camera.h"
#include"../public/vec3.h"
#include"../public/ray.h"

camera::camera(int image_width, int image_height) 
 {
    const double aspect_ratio = double(image_width) / image_height;
    const double viewport_height = 2.0;
    const double viewport_width = aspect_ratio * viewport_height;
    const double focal_length = 1.0;

    origin = vec3(0.0, 0.0, 0.0);
    
    horizontal = vec3(viewport_width, 0.0, 0.0);
    vertical = vec3(0.0, viewport_height, 0.0);
    
    lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
}

ray camera::get_ray(double u, double v) 
{
    return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}
