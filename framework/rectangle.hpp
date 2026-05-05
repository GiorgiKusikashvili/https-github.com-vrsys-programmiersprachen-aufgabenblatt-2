#ifndef BUW_RECTANGLE_HPP
#define BUW_RECTANGLE_HPP
#include "vec2.hpp"

namespace buw {
    class Rectangle
    {
    public:
        // Konstruktoren
        Rectangle();
        Rectangle(Vec2 const& min, Vec2 const& max);
        Rectangle(double min_x, double min_y, double max_x, double max_y);

        // Öffentliche Attribute (achsenparalleles Rechteck)
        Vec2 min;  // linke obere Ecke
        Vec2 max;  // rechte untere Ecke
    };
}

#endif //BUW_RECTANGLE_HPP