#define DOCTEST_CONFIG_IMPLEMENT
#include "../external/doctest/doctest.h"
#include "../framework/vec2.hpp"

int factorial(int n)
{
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

TEST_CASE("factorial computes n!")
{
  CHECK(factorial(0) == 1);
  CHECK(factorial(1) == 1);
  CHECK(factorial(5) == 120);
  CHECK(factorial(10) == 3628800);
}
TEST_CASE("vec2 default member initialisation")
{
  buw::Vec2 a;
  CHECK(a.x == 0.0f);
  CHECK(a.y == 0.0f);
}
TEST_CASE("vec2  Aggregatinitialisierung")
{
  buw::Vec2 b{5.1f, -9.3f}; 
  CHECK(b.x == doctest::Approx(5.1f));
  CHECK(b.y == doctest::Approx(-9.3f));
}
TEST_CASE("Vec2 operator+= beide Vektoren sind positiv")
{
  buw::Vec2 a{2.0f, 3.0f};
  buw::Vec2 b{1.5f, 2.5f};

  a += b;

  CHECK(a.x == doctest::Approx(3.5f));
  CHECK(a.y == doctest::Approx(5.5f));
  CHECK(b.x == doctest::Approx(1.5f)); //das bleibt uverändert
  CHECK(b.y == doctest::Approx(2.5f)); //das aucg
}
TEST_CASE("Vec2  operator+= eine Vektor ist negativ")
{
  buw::Vec2 a{5.0f, 5.0f};
  buw::Vec2 b{-3.0f, -2.0f};

  a += b;

  CHECK(a.x == doctest::Approx(2.0f));
  CHECK(a.y == doctest::Approx(3.0f));
}

TEST_CASE("Vec2  operator+= mit einer Nullvektor")
{
  buw::Vec2 a{5.0f, 7.0f};
  buw::Vec2 b{0.0f, 0.0f};

  a += b;

  CHECK(a.x == doctest::Approx(5.0f));
  CHECK(a.y == doctest::Approx(7.0f));
}
TEST_CASE("Vec2  operator-= mit negativem Ergebnis")
{
  buw::Vec2 a{3.0f, 2.0f};
  buw::Vec2 b{5.0f, 4.0f};

  a -= b;

  CHECK(a.x == doctest::Approx(-2.0f));
  CHECK(a.y == doctest::Approx(-2.0f));
}
TEST_CASE("Vec2  operator*= mutliplikation mit einer postivie zahl")
{
  buw::Vec2 a{3.0f, 4.0f};

  a *= 2.5;

  CHECK(a.x == doctest::Approx(7.5f));
  CHECK(a.y == doctest::Approx(10.0f));
}

TEST_CASE("Vec2  operator*= mutliplikation mit Null")
{
  buw::Vec2 a{3.0f, 4.0f};

  a *= 0.0;

  CHECK(a.x == doctest::Approx(0.0f));
  CHECK(a.y == doctest::Approx(0.0f));
}

TEST_CASE("Vec2  operator*= mutliplikation mit negativer zahl")
{
  buw::Vec2 a{3.0f, 4.0f};

  a *= -2.0;

  CHECK(a.x == doctest::Approx(-6.0f));
  CHECK(a.y == doctest::Approx(-8.0f));
}

TEST_CASE("Vec2  operator*= multiplikation mit 1")
{
  buw::Vec2 a{3.0f, 4.0f};

  a *= 1.0;

  CHECK(a.x == doctest::Approx(3.0f));
  CHECK(a.y == doctest::Approx(4.0f));
}

TEST_CASE("Vec2  operator/= division mit positiver zahl")
{
  buw::Vec2 a{6.0f, 9.0f};

  a /= 3.0;

  CHECK(a.x == doctest::Approx(2.0f));
  CHECK(a.y == doctest::Approx(3.0f));
}

TEST_CASE("Vec2  operator/= division mit negativer zahl")
{
  buw::Vec2 a{6.0f, 9.0f};

  a /= -3.0;

  CHECK(a.x == doctest::Approx(-2.0f));
  CHECK(a.y == doctest::Approx(-3.0f));
}

TEST_CASE("Vec2  operator/= division mit 1")
{
  buw::Vec2 a{6.0f, 9.0f};

  a /= 1.0;

  CHECK(a.x == doctest::Approx(6.0f));
  CHECK(a.y == doctest::Approx(9.0f));
}

// ============================================
// Tests für freie Funktionen (Aufgabe 2.4)
// ============================================

TEST_CASE("Vec2 operator+ (freie Funktion)")
{
    buw::Vec2 a{2.0f, 3.0f};
    buw::Vec2 b{1.5f, 2.5f};

    buw::Vec2 c = a + b;

    CHECK(c.x == doctest::Approx(3.5f));
    CHECK(c.y == doctest::Approx(5.5f));
    // a und b sollten unverändert sein
    CHECK(a.x == doctest::Approx(2.0f));
    CHECK(a.y == doctest::Approx(3.0f));
    CHECK(b.x == doctest::Approx(1.5f));
    CHECK(b.y == doctest::Approx(2.5f));
}

TEST_CASE("Vec2 operator+ mit Nullvektor")
{
    buw::Vec2 a{5.0f, 7.0f};
    buw::Vec2 b{0.0f, 0.0f};

    buw::Vec2 c = a + b;

    CHECK(c.x == doctest::Approx(5.0f));
    CHECK(c.y == doctest::Approx(7.0f));
}

TEST_CASE("Vec2 operator+ mit negativen Werten")
{
    buw::Vec2 a{5.0f, 5.0f};
    buw::Vec2 b{-3.0f, -2.0f};

    buw::Vec2 c = a + b;

    CHECK(c.x == doctest::Approx(2.0f));
    CHECK(c.y == doctest::Approx(3.0f));
}

TEST_CASE("Vec2 operator- (freie Funktion)")
{
    buw::Vec2 a{5.0f, 8.0f};
    buw::Vec2 b{2.0f, 3.0f};

    buw::Vec2 c = a - b;

    CHECK(c.x == doctest::Approx(3.0f));
    CHECK(c.y == doctest::Approx(5.0f));
    CHECK(a.x == doctest::Approx(5.0f));
    CHECK(a.y == doctest::Approx(8.0f));
}

TEST_CASE("Vec2 operator- mit Nullvektor")
{
    buw::Vec2 a{5.0f, 7.0f};
    buw::Vec2 b{0.0f, 0.0f};

    buw::Vec2 c = a - b;

    CHECK(c.x == doctest::Approx(5.0f));
    CHECK(c.y == doctest::Approx(7.0f));
}

TEST_CASE("Vec2 operator- mit negativem Ergebnis")
{
    buw::Vec2 a{3.0f, 2.0f};
    buw::Vec2 b{5.0f, 4.0f};

    buw::Vec2 c = a - b;

    CHECK(c.x == doctest::Approx(-2.0f));
    CHECK(c.y == doctest::Approx(-2.0f));
}

TEST_CASE("Vec2 operator* (Vec2 * double) - freie Funktion")
{
    buw::Vec2 a{3.0f, 4.0f};

    buw::Vec2 c = a * 2.5;

    CHECK(c.x == doctest::Approx(7.5f));
    CHECK(c.y == doctest::Approx(10.0f));

}

TEST_CASE("Vec2 operator* mit Null")
{
    buw::Vec2 a{3.0f, 4.0f};

    buw::Vec2 c = a * 0.0;

    CHECK(c.x == doctest::Approx(0.0f));
    CHECK(c.y == doctest::Approx(0.0f));
}

TEST_CASE("Vec2 operator* mit negativem Skalar")
{
    buw::Vec2 a{3.0f, 4.0f};

    buw::Vec2 c = a * (-2.0);

    CHECK(c.x == doctest::Approx(-6.0f));
    CHECK(c.y == doctest::Approx(-8.0f));
}

TEST_CASE("Vec2 operator* (double * Vec2) - freie Funktion (Kommutativität)")
{
    buw::Vec2 a{3.0f, 4.0f};

    buw::Vec2 c = 2.5 * a;

    CHECK(c.x == doctest::Approx(7.5f));
    CHECK(c.y == doctest::Approx(10.0f));
}

TEST_CASE("Vec2 operator* Kommutativität von a*s und s*a")
{
    buw::Vec2 a{3.0f, 4.0f};

    buw::Vec2 c1 = a * 2.5;
    buw::Vec2 c2 = 2.5 * a;

    CHECK(c1.x == doctest::Approx(c2.x));
    CHECK(c1.y == doctest::Approx(c2.y));
}

TEST_CASE("Vec2 operator/ (freie Funktion)")
{
    buw::Vec2 a{6.0f, 9.0f};

    buw::Vec2 c = a / 3.0;

    CHECK(c.x == doctest::Approx(2.0f));
    CHECK(c.y == doctest::Approx(3.0f));
}

TEST_CASE("Vec2 operator/ mit negativem Skalar")
{
    buw::Vec2 a{6.0f, 9.0f};

    buw::Vec2 c = a / (-3.0);

    CHECK(c.x == doctest::Approx(-2.0f));
    CHECK(c.y == doctest::Approx(-3.0f));
}

TEST_CASE("Vec2 operator/ mit 1")
{
    buw::Vec2 a{6.0f, 9.0f};

    buw::Vec2 c = a / 1.0;

    CHECK(c.x == doctest::Approx(6.0f));
    CHECK(c.y == doctest::Approx(9.0f));
}




int main(int argc, char *argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
