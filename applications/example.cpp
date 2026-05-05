#include "vec2.hpp"
#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <GLFW/glfw3.h>
#include <cmath>

int main(int argc, char* argv[])
{
  buw::Window win{std::make_pair(800, 800)};

  // Erstelle Formen
  buw::Color red{1.0, 0.0, 0.0};
  buw::Circle circle(buw::Vec2(400.0f, 400.0f), 150.0, red);

  buw::Color blue{0.0, 0.0, 1.0};
  buw::Rectangle rectangle(buw::Vec2(100.0f, 100.0f), buw::Vec2(700.0f, 550.0f), blue);

  double thickness = 1.0;
  bool increasing = true;

  while (!win.should_close())
  {
    // Ändere die Liniendicke animiert
    if (increasing)
    {
      thickness += 0.5;
      if (thickness >= 15.0) increasing = false;
    }
    else
    {
      thickness -= 0.5;
      if (thickness <= 1.0) increasing = true;
    }

    //  Zeichne mit unterschiedlichen Dicken
    rectangle.draw(win, thickness);
    circle.draw(win, thickness * 0.8);

    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      win.close();
    }

    win.update();
  }

  return 0;
}
