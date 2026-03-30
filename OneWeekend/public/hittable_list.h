#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "object/hittable.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list: public hittable {
public:
    hittable_list();
    hittable_list(shared_ptr<hittable> object);
    ~hittable_list();

    void clear();
    void add(shared_ptr<hittable> object);

    virtual bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const;

private:
    std::vector<shared_ptr<hittable>> objects;
};

#endif