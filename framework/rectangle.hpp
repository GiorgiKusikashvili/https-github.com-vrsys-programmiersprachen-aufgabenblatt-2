#ifndef BUW_RECTANGLE_HPP
#define BUW_RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

namespace buw {

    class Window;

    class Rectangle
    {
    public:
        // Konstruktoren
        Rectangle();
        Rectangle(Vec2 const& min, Vec2 const& max);
        Rectangle(double min_x, double min_y, double max_x, double max_y);
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
        Rectangle(double min_x, double min_y, double max_x, double max_y, Color const& color);

        double circumference() const;
        void draw(Window& window) const;
        void draw(Window& window, double thickness) const;  // überladene Methode

        // Öffentliche Attribute
        Vec2 min;  // linke obere Ecke
        Vec2 max;  // rechte untere Ecke
        Color color;
    };
}

#endif //BUW_RECTANGLE_HPP