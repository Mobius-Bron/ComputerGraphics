#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"
#include "vec3.h"
#include "ray.h"

class camera {
public:
    camera(int image_width, int image_height);
    
    camera(
        vec3 lookfrom, vec3 lookat, vec3 vup,
        double vfov,
        double aspect_ratio, double aperture, double focus_dist
    );

    ray get_ray(double s, double t);

private:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u, v, w;
    double lens_radius;
};
#endif
