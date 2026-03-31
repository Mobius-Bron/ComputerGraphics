#include "../../public/Material/dielectric.h"
#include "../../public/vec3.h"
#include "../../public/ray.h"
#include "../../public/rtweekend.h"
#include "../../public/hittable_list.h"

bool dielectric::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
    attenuation = vec3(1.0, 1.0, 1.0);
    double etai_over_etat = (rec.front_face) ? (1.0 / ref_idx) : (ref_idx);

    vec3 unit_direction = unit_vector(r_in.direction());
    double cos_theta = ffmin(dot(-unit_direction, rec.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);
    
    // 发生折射
    if (etai_over_etat * sin_theta < 1.0) {
        vec3 refracted = refract(unit_direction, rec.normal, etai_over_etat);
        scattered = ray(rec.p, refracted);
        return true;
    }
    // 发生反射
    else {
        vec3 reflected = reflect(unit_direction, rec.normal);
        scattered = ray(rec.p, reflected);
        return true;
    }
}