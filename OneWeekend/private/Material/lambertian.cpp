#include "../../public/Material/lambertian.h"
#include "../../public/vec3.h"
#include "../../public/ray.h"
#include "../../public/rtweekend.h"
#include "../../public/hittable_list.h"

bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
{
    vec3 scatter_direction = rec.normal + random_unit_vector();
    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}