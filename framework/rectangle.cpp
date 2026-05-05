#include "rectangle.hpp"

namespace buw {
    Rectangle::Rectangle()
        : min(0.0f, 0.0f), max(1.0f, 1.0f), color()
    {}

    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max)
        : min(min), max(max), color()
    {}

    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color)
        : min(min), max(max), color(color)
    {}

    Rectangle::Rectangle(double min_x, double min_y, double max_x, double max_y)
        : min(static_cast<float>(min_x), static_cast<float>(min_y)),
          max(static_cast<float>(max_x), static_cast<float>(max_y)),
          color()
    {}

    Rectangle::Rectangle(double min_x, double min_y, double max_x, double max_y, Color const& color)
        : min(static_cast<float>(min_x), static_cast<float>(min_y)),
          max(static_cast<float>(max_x), static_cast<float>(max_y)),
          color(color)
    {}

    double Rectangle::circumference() const
    {
        double width = max.x - min.x;
        double height = max.y - min.y;
        return 2.0 * (width + height);
    }
}