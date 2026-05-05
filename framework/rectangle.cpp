#include "rectangle.hpp"

#include "window.hpp"

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

    void Rectangle::draw(Window& window) const
    {
        draw(window, 2.0);  // Default Dicke = 2.0
    }

    void Rectangle::draw(Window& window, double thickness) const
    {
        // Zeichne die vier Seiten des Rechtecks
        // Obere Kante
        window.draw_line(min.x, min.y, max.x, min.y, color.r, color.g, color.b, 2.0);
        // Rechte Kante
        window.draw_line(max.x, min.y, max.x, max.y, color.r, color.g, color.b, 2.0);
        // Untere Kante
        window.draw_line(max.x, max.y, min.x, max.y, color.r, color.g, color.b, 2.0);
        // Linke Kante
        window.draw_line(min.x, max.y, min.x, min.y, color.r, color.g, color.b, 2.0);
    }
    bool Rectangle::is_inside(Vec2 const& point) const
    {

        return (point.x >= min.x && point.x <= max.x &&
                point.y >= min.y && point.y <= max.y);
    }
}
