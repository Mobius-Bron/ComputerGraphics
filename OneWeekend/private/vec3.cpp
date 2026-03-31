#include "../public/vec3.h"
#include "../public/rtweekend.h"

vec3::vec3() : e{0, 0, 0} {}

vec3::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double vec3::x() const { 
    return e[0]; 
}

double vec3::y() const { 
    return e[1]; 
}

double vec3::z() const { 
    return e[2]; 
}

const double* vec3::get_e() const { 
    return e; 
}

vec3 vec3::operator-() const { 
    return vec3(-e[0], -e[1], -e[2]); 
}

double vec3::operator[](int i) const { 
    return e[i]; 
}

double& vec3::operator[](int i) { 
    return e[i]; 
}

vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3& vec3::operator/=(double t) {
    return *this *= 1/t;
}

double vec3::length() const {
    return std::sqrt(length_squared());
}

double vec3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

void vec3::write_color(std::ostream &out) {
    out << static_cast<int>(255.999 * e[0]) << ' '
        << static_cast<int>(255.999 * e[1]) << ' '
        << static_cast<int>(255.999 * e[2]) << '\n';
}

void vec3::write_color(std::ostream &out, int samples_per_pixel) {
    auto scale = 1.0 / samples_per_pixel;
    // 使用"gamma 2"空间进行颜色校正
    auto r = sqrt(scale * e[0]);
    auto g = sqrt(scale * e[1]);
    auto b = sqrt(scale * e[2]);

    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

vec3 vec3::random() {
    return vec3(random_double(), random_double(), random_double());
}

vec3 vec3::random(double min, double max) {
    return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
}

std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.get_e()[0] << ' ' << v.get_e()[1] << ' ' << v.get_e()[2];
}

vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.get_e()[0] + v.get_e()[0], 
                u.get_e()[1] + v.get_e()[1], 
                u.get_e()[2] + v.get_e()[2]);
}

vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.get_e()[0] - v.get_e()[0], 
                u.get_e()[1] - v.get_e()[1], 
                u.get_e()[2] - v.get_e()[2]);
}

vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.get_e()[0] * v.get_e()[0], 
                u.get_e()[1] * v.get_e()[1], 
                u.get_e()[2] * v.get_e()[2]);
}

vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v.get_e()[0], 
                t * v.get_e()[1], 
                t * v.get_e()[2]);
}

vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

double dot(const vec3 &u, const vec3 &v) {
    return u.get_e()[0] * v.get_e()[0] +
           u.get_e()[1] * v.get_e()[1] +
           u.get_e()[2] * v.get_e()[2];
}

vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.get_e()[1] * v.get_e()[2] - u.get_e()[2] * v.get_e()[1],
                u.get_e()[2] * v.get_e()[0] - u.get_e()[0] * v.get_e()[2],
                u.get_e()[0] * v.get_e()[1] - u.get_e()[1] * v.get_e()[0]);
}

vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}

vec3 unit_vector(vec3 v) {
    return v / v.length();
}

vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1,1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

vec3 random_unit_vector() {
    auto a = random_double(0, 2*pi);
    auto z = random_double(-1, 1);
    auto r = sqrt(1 - z*z);
    return vec3(r*cos(a), r*sin(a), z);
}