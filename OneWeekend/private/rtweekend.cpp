#include"../public/rtweekend.h"

inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180;
}

inline double ffmin(double a, double b) 
{ 
    return a <= b ? a : b; 
}

inline double ffmax(double a, double b) 
{ 
    return a >= b ? a : b; 
}

