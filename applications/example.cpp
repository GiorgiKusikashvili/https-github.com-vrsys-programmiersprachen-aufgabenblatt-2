#include "vec2.hpp"
#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    buw::Window win{std::make_pair(800, 800)};

    // Ein Kreis
    buw::Color red{1.0, 0.0, 0.0};
    buw::Circle circle(buw::Vec2(400.0f, 400.0f), 150.0, red);

    // Ein Rechteck
    buw::Color blue{0.0, 0.0, 1.0};
    buw::Rectangle rectangle(buw::Vec2(100.0f, 100.0f), buw::Vec2(300.0f, 250.0f), blue);

    while (!win.should_close())
    {
        // Mausposition
        auto mouse_pos = win.mouse_position();
        buw::Vec2 mouse(mouse_pos.first, mouse_pos.second);

        // Kreis: dicker wenn Maus drin
        if (circle.is_inside(mouse))
            circle.draw(win, 4.0);  // doppelte Dicke
        else
            circle.draw(win, 2.0);  // normale Dicke

        // Rechteck: dicker wenn Maus drin
        if (rectangle.is_inside(mouse))
            rectangle.draw(win, 4.0);
        else
            rectangle.draw(win, 2.0);

        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS)
            win.close();

        win.update();
    }

    return 0;
}