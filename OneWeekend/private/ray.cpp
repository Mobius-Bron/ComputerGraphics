#include "../public/ray.h"

ray::ray() {}

ray::ray(const vec3& origin, const vec3& direction)
    : orig(origin), dir(direction)
{}

vec3 ray::origin() const {
    return orig;
}

vec3 ray::direction() const {
    return dir;
}

vec3 ray::at(double t) const {
    return orig + t * dir;
}