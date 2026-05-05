#include "circle.hpp"

namespace buw {
    Circle::Circle() : center(0.0f, 0.0f), radius(1.0) {}

    Circle::Circle(Vec2 const& center, double radius) : center(center), radius(radius) {}

    Circle::Circle(double center_x, double center_y, double radius) : center(static_cast<float>(center_x), static_cast<float>(center_y)), radius(radius) {}

}

