#include "../../public/Material/metal.h"
#include "../../public/vec3.h"
#include "../../public/ray.h"
#include "../../public/rtweekend.h"
#include "../../public/hittable_list.h"

bool metal::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected);
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}