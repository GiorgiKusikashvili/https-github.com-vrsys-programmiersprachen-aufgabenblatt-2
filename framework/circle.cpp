#include "circle.hpp"

#include <math.h>

namespace buw {
    Circle::Circle() : center(0.0f, 0.0f), radius(1.0) {}

    Circle::Circle(Vec2 const& center, double radius) : center(center), radius(radius) {}

    Circle::Circle(double center_x, double center_y, double radius) : center(static_cast<float>(center_x), static_cast<float>(center_y)), radius(radius) {}
    double Circle::circumference() const
    {
        // Umfang eines Kreises: U = 2 * π * r
        return 2.0 * M_PI * radius;
    }

}


