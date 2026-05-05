#ifndef BUW_CIRCLE_HPP
#define BUW_CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

namespace buw {

    class Window;
    class Circle
    {
    public:
        // Konstruktoren
        Circle();
        Circle(Vec2 const& center, double radius);
        Circle(double center_x, double center_y, double radius);
        Circle(double center_x, double center_y, double radius, Color const& color);
        Circle(Vec2 const& center, double radius, Color const& color);

        double circumference() const;
        void draw(Window& window) const;
        void draw(Window& window, double thickness) const;// überladene Methode
        bool is_inside(Vec2 const& point) const;
        
        // Öffentliche Attribute weil wir keine Getter/Setter brauchen
        Vec2 center;
        double radius;
        Color color;


    };
}

#endif //BUW_CIRCLE_HPP