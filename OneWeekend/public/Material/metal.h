#ifndef METAL_H
#define METAL_H 

#include "material.h"
#include "../ray.h"
#include "../vec3.h"
#include "../rtweekend.h"
#include "../Object/hittable.h"

class metal : public material {
    public:
        metal(const vec3& a) : albedo(a) {}

        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const override;

    public:
        vec3 albedo;
};

#endif