//sphere.h
#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "../Material/material.h"

class sphere: public hittable {
public:
    sphere() {}
    sphere(vec3 cen, double r, shared_ptr<material> m)
     : center(cen), radius(r), mat_ptr(m) {};

    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override;

private:
    vec3 center;
    double radius;
    shared_ptr<material> mat_ptr;
};

#endif