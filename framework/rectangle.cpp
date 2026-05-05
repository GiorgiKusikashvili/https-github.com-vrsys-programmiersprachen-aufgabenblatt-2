#include "rectangle.hpp"

namespace buw {
    Rectangle::Rectangle() : min(0.0f, 0.0f), max(1.0f, 1.0f) {}

    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) : min(min), max(max) {}

    Rectangle::Rectangle(double min_x, double min_y, double max_x, double max_y) : min(static_cast<float>(min_x), static_cast<float>(min_y)), max(static_cast<float>(max_x), static_cast<float>(max_y)) {}
    double Rectangle::circumference() const
    {
        // Umfang eines Rechtecks: U = 2 * (Breite + Höhe)
        double width = max.x - min.x;
        double height = max.y - min.y;
        return 2.0 * (width + height);
    }
}