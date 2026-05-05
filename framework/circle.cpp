#include "circle.hpp"

#include <cmath>

#include "window.hpp"

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
    void Circle::draw(Window& window) const
    {
        const int segments = 36;
        double angle_step = 2.0 * M_PI / segments;

        // Erster Punkt
        double x1 = center.x + radius * std::cos(0.0);
        double y1 = center.y + radius * std::sin(0.0);

        for (int i = 1; i <= segments; ++i)
        {
            double angle = i * angle_step;
            double x2 = center.x + radius * std::cos(angle);
            double y2 = center.y + radius * std::sin(angle);

            // Verwende die draw_line Methode mit Farbe und Dicke
            window.draw_line(x1, y1, x2, y2, color.r, color.g, color.b, 2.0);

            x1 = x2;
            y1 = y2;
        }
    }
}




