#include "circle.hpp"

#include <cmath>

namespace buw {
    Circle::Circle()
    : center(0.0f, 0.0f), radius(1.0), color()
    {}

    Circle::Circle(Vec2 const& center, double radius)
        : center(center), radius(radius), color()
    {}

    Circle::Circle(Vec2 const& center, double radius, Color const& color)
        : center(center), radius(radius), color(color)
    {}

    Circle::Circle(double center_x, double center_y, double radius)
        : center(static_cast<float>(center_x), static_cast<float>(center_y)), radius(radius), color()
    {}

    Circle::Circle(double center_x, double center_y, double radius, Color const& color)
        : center(static_cast<float>(center_x), static_cast<float>(center_y)), radius(radius), color(color)
    {}

    double Circle::circumference() const
    {
        return 2.0 * M_PI * radius;
    }

}




