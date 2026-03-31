#include"../public/camera.h"
#include"../public/vec3.h"
#include"../public/ray.h"

camera::camera(int image_width, int image_height)
 {
    lower_left_corner = vec3(-2.0, -1.0, -1.0);
    horizontal = vec3(image_width/100, 0.0, 0.0);
    vertical = vec3(0.0, image_height/100, 0.0);
    origin = vec3(0.0, 0.0, 0.0);
}

ray camera::get_ray(double u, double v) 
{
    return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}