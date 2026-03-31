#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"
class ray;
class vec3;


class camera {
public:
    camera(int image_width, int image_height);

    ray get_ray(double u, double v);

private:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};
#endif