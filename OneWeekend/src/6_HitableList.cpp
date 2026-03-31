#include <iostream>
#include "../public/vec3.h"
#include "../public/ray.h"
#include "../public/rtweekend.h"
#include "../public/hittable_list.h"
#include "../public/object/sphere.h"
#include "../public/camera.h"

vec3 ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + vec3(1,1,1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main() {
    const int image_width = 720;
    const int image_height = 480;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    hittable_list world;
    world.add(make_shared<sphere>(vec3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(vec3(-1,0,-2), 0.7));
    world.add(make_shared<sphere>(vec3(2,0,-2), 1));
    world.add(make_shared<sphere>(vec3(0,-100.5,-1), 100));

    camera cam(image_width, image_height);

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / image_width;
            auto v = double(j) / image_height;
            ray r = cam.get_ray(u, v);
            vec3 color = ray_color(r, world);

            color.write_color(std::cout);
        }
    }

    std::cerr << "\nDone.\n";
}