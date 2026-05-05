#ifndef BUW_CIRCLE_HPP
#define BUW_CIRCLE_HPP
#include "vec2.hpp"

namespace buw {

    class Circle
    {
    public:
        // Konstruktoren
        Circle();
        Circle(Vec2 const& center, double radius);
        Circle(double center_x, double center_y, double radius);

        double circumference() const;

        // Öffentliche Attribute weil wir keine Getter/Setter brauchen
        Vec2 center;
        double radius;



    };
}

#endif //BUW_CIRCLE_HPP