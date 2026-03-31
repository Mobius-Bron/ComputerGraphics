#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include"material.h"
#include "../ray.h"
#include "../vec3.h"
#include "../rtweekend.h"


class dielectric : public material {
    public:
        dielectric(double ri) : ref_idx(ri) {}

        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

        double ref_idx;
};

#endif