//sphere.h
#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere: public hittable {
public:
    sphere() {}
    sphere(vec3 cen, double r) : center(cen), radius(r) {};

    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;

private:
    vec3 center;
    double radius;
};

#endif