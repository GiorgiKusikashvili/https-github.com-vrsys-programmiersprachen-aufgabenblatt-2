#define DOCTEST_CONFIG_IMPLEMENT
#include "mat2.hpp"
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


// Tests für freie Funktionen (Aufgabe 2.4)


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

// Tests für Mat2 (Aufgabe 2.5)

TEST_CASE("Mat2 - Standardinitialisierung (Einheitsmatrix)")
{ //um zu sehen ob es default geht
    buw::Mat2 m;

    CHECK(m.e_00 == doctest::Approx(1.0));
    CHECK(m.e_10 == doctest::Approx(0.0));
    CHECK(m.e_01 == doctest::Approx(0.0));
    CHECK(m.e_11 == doctest::Approx(1.0));
}

TEST_CASE("Mat2 - Aggregatinitialisierung")
{ //um zu7 sehen ob es aggregativierung geht
    buw::Mat2 m{2.0, 3.0, 4.0, 5.0};

    CHECK(m.e_00 == doctest::Approx(2.0));
    CHECK(m.e_10 == doctest::Approx(3.0));
    CHECK(m.e_01 == doctest::Approx(4.0));
    CHECK(m.e_11 == doctest::Approx(5.0));
}

TEST_CASE("Mat2  operator*= mutliplikation defaultmatrix mit aggregatmatrix (Memberfunktion)")
{
    buw::Mat2 m{2.0, 3.0, 4.0, 5.0}; //aggregatmatrix
    buw::Mat2 defaultMatrix; //defalut matrix also: e_00 = 1.0 , e_10 = 1.0 , e_01 = 1.0 , e_11 = 1.0

    m *= defaultMatrix;

    CHECK(m.e_00 == doctest::Approx(2.0));
    CHECK(m.e_10 == doctest::Approx(3.0));
    CHECK(m.e_01 == doctest::Approx(4.0));
    CHECK(m.e_11 == doctest::Approx(5.0));
}

TEST_CASE("Mat2  operator*= Multiplikation einer matrix mit anderen (Memberfunktion)")
{
    buw::Mat2 a{2.0, 3.0, 4.0, 5.0};
    buw::Mat2 b{1.0, 2.0, 3.0, 4.0};

    // Matrixmultiplikation: a * b
    // [2 3]   [1 2]   [2*1+3*3  2*2+3*4]   [2+9   4+12]   [11 16]
    // [4 5] * [3 4] = [4*1+5*3  4*2+5*4] = [4+15  8+20] = [19 28]

    a *= b;

    CHECK(a.e_00 == doctest::Approx(11.0));
    CHECK(a.e_10 == doctest::Approx(16.0));
    CHECK(a.e_01 == doctest::Approx(19.0));
    CHECK(a.e_11 == doctest::Approx(28.0));
}

TEST_CASE("Mat2  operator*= Multiplikation mit Nullmatrix")
{
    buw::Mat2 a{2.0, 3.0, 4.0, 5.0};
    buw::Mat2 zero{0.0, 0.0, 0.0, 0.0};

    a *= zero;

    CHECK(a.e_00 == doctest::Approx(0.0));
    CHECK(a.e_10 == doctest::Approx(0.0));
    CHECK(a.e_01 == doctest::Approx(0.0));
    CHECK(a.e_11 == doctest::Approx(0.0));
}
TEST_CASE("Mat2 - operator*= mit negativen Werten ")
{
    buw::Mat2 a{2.0, -3.0, 4.0, -5.0};
    buw::Mat2 b{-1.0, 2.0, -3.0, 4.0};

    a *= b;

    CHECK(a.e_00 == doctest::Approx(7.0));
    CHECK(a.e_10 == doctest::Approx(-8.0));
    CHECK(a.e_01 == doctest::Approx(11.0));
    CHECK(a.e_11 == doctest::Approx(-12.0));
}

//freie Funktionstests

TEST_CASE("Mat2  operator* Multiplikation mit 2 Matrizen")
{
    buw::Mat2 a{2.0, 3.0, 4.0, 5.0};
    buw::Mat2 b{1.0, 2.0, 3.0, 4.0};

    // ^Multiplikation geht so: a * b
    // [2 3]   [1 2]   [11 16]
    // [4 5] * [3 4] = [19 28]

    buw::Mat2 result = a * b;

    CHECK(result.e_00 == doctest::Approx(11.0));
    CHECK(result.e_10 == doctest::Approx(16.0));
    CHECK(result.e_01 == doctest::Approx(19.0));
    CHECK(result.e_11 == doctest::Approx(28.0));

    // a und b sollten unverändert sein
    CHECK(a.e_00 == doctest::Approx(2.0));
    CHECK(b.e_00 == doctest::Approx(1.0));
}

TEST_CASE("Mat2  operator* (freie Funktion) mit Nullmatrix")
{
    buw::Mat2 a{2.0, 3.0, 4.0, 5.0};
    buw::Mat2 zero{0.0, 0.0, 0.0, 0.0};

    buw::Mat2 result = a * zero;

    CHECK(result.e_00 == doctest::Approx(0.0));
    CHECK(result.e_10 == doctest::Approx(0.0));
    CHECK(result.e_01 == doctest::Approx(0.0));
    CHECK(result.e_11 == doctest::Approx(0.0));
}
TEST_CASE("Mat2 - operator* (freie Funktion) mit negativen Werten")
{
    buw::Mat2 a{2.0, -1.0, -3.0, 4.0};
    buw::Mat2 b{-2.0, 3.0, 1.0, -4.0};

    buw::Mat2 result = a * b;

    CHECK(result.e_00 == doctest::Approx(-5.0));
    CHECK(result.e_10 == doctest::Approx(10.0));
    CHECK(result.e_01 == doctest::Approx(10.0));
    CHECK(result.e_11 == doctest::Approx(-25.0));

}

TEST_CASE("Mat2 - operator* mit zwei negativen Matrizen (Minus * Minus = Plus)")
{
    buw::Mat2 a{-2.0, -1.0, -3.0, -2.0};
    buw::Mat2 b{-1.0, -2.0, -3.0, -4.0};


    buw::Mat2 result = a * b;

    CHECK(result.e_00 == doctest::Approx(5.0));
    CHECK(result.e_10 == doctest::Approx(8.0));
    CHECK(result.e_01 == doctest::Approx(9.0));
    CHECK(result.e_11 == doctest::Approx(14.0));
}



// Tests für Mat2 * Vec2 (Aufgabe 2.6)
TEST_CASE("Mat2 * Vec2 ")
{

    buw::Mat2 m1{2.0, 0.0, 0.0, 2.0};
    buw::Vec2 v{3.0f, 4.0f};

    buw::Vec2 result = m1 * v;

    // [2 0]   [3]   [6]
    // [0 2] * [4] = [8]
    CHECK(result.x == doctest::Approx(6.0f));
    CHECK(result.y == doctest::Approx(8.0f));
}

TEST_CASE("Mat2 * Vec2")
{
    buw::Mat2 m1{2.0, 0.0, 0.0, 3.0};
    buw::Vec2 v{3.0f, 4.0f};

    buw::Vec2 result = m1 * v;

    CHECK(result.x == doctest::Approx(6.0f));
    CHECK(result.y == doctest::Approx(12.0f));
}

TEST_CASE("Mat2 * Vec2 ")
{

    buw::Mat2 m1{1.0, 2.0, 0.0, 1.0};
    buw::Vec2 v{2.0f, 3.0f};

    buw::Vec2 result = m1 * v;

    // [1 2]   [2]   [2 + 6]   [8]
    // [0 1] * [3] = [0 + 3] = [3]
    CHECK(result.x == doctest::Approx(8.0f));
    CHECK(result.y == doctest::Approx(3.0f));
}

TEST_CASE("Mat2 * Vec2 - Allgemeine Matrix")
{
    buw::Mat2 m{2.0, 3.0, 4.0, 5.0};
    buw::Vec2 v{1.0f, 2.0f};

    buw::Vec2 result = m * v;

    // [2 3]   [1]   [2*1 + 3*2]   [2 + 6]   [8]
    // [4 5] * [2] = [4*1 + 5*2] = [4 + 10] = [14]
    CHECK(result.x == doctest::Approx(8.0f));
    CHECK(result.y == doctest::Approx(14.0f));
}

TEST_CASE("Mat2 * Vec2 - Mit Nullmatrix")
{
    buw::Mat2 zero{0.0, 0.0, 0.0, 0.0};
    buw::Vec2 v{3.0f, 4.0f};

    buw::Vec2 result = zero * v;

    CHECK(result.x == doctest::Approx(0.0f));
    CHECK(result.y == doctest::Approx(0.0f));
}

TEST_CASE("Mat2 * Vec2 - Mit negativen Werten")
{
    buw::Mat2 m{-2.0, 3.0, -4.0, 5.0};
    buw::Vec2 v{1.0f, -2.0f};

    buw::Vec2 result = m * v;

    // [-2  3]   [1]   [-2*1 + 3*(-2)]   [-2 - 6]   [-8]
    // [-4  5] * [-2] = [-4*1 + 5*(-2)] = [-4 - 10] = [-14]
    CHECK(result.x == doctest::Approx(-8.0f));
    CHECK(result.y == doctest::Approx(-14.0f));
}





// Tests für make_rotation_mat2 (Aufgabe 2.6)



TEST_CASE("make_rotation_mat2 - Rotation um 90° (π/2)")
{
    double phi = 3.141592653589793 / 2.0; // π/2
    buw::Mat2 rot = buw::make_rotation_mat2(phi);

    // Rotationsmatrix für 90°:
    // [cos(90°) -sin(90°)]   [0  -1]
    // [sin(90°)  cos(90°)] = [1   0]
    CHECK(rot.e_00 == doctest::Approx(0.0).epsilon(0.0001));
    CHECK(rot.e_10 == doctest::Approx(-1.0).epsilon(0.0001));
    CHECK(rot.e_01 == doctest::Approx(1.0).epsilon(0.0001));
    CHECK(rot.e_11 == doctest::Approx(0.0).epsilon(0.0001));
}

TEST_CASE("make_rotation_mat2 - Rotation um 180° (π)")
{
    double phi = 3.141592653589793; // π
    buw::Mat2 rot = buw::make_rotation_mat2(phi);

    // Rotationsmatrix für 180°:
    // [cos(180°) -sin(180°)]   [-1   0]
    // [sin(180°)  cos(180°)] = [ 0  -1]
    CHECK(rot.e_00 == doctest::Approx(-1.0).epsilon(0.0001));
    CHECK(rot.e_10 == doctest::Approx(0.0).epsilon(0.0001));
    CHECK(rot.e_01 == doctest::Approx(0.0).epsilon(0.0001));
    CHECK(rot.e_11 == doctest::Approx(-1.0).epsilon(0.0001));
}

TEST_CASE("make_rotation_mat2 - Rotation um 270° (3π/2)")
{
    double phi = 3.0 * 3.141592653589793 / 2.0; // 3π/2
    buw::Mat2 rot = buw::make_rotation_mat2(phi);

    // Rotationsmatrix für 270°:
    // [cos(270°) -sin(270°)]   [0   1]
    // [sin(270°)  cos(270°)] = [-1  0]
    CHECK(rot.e_00 == doctest::Approx(0.0).epsilon(0.0001));
    CHECK(rot.e_10 == doctest::Approx(1.0).epsilon(0.0001));
    CHECK(rot.e_01 == doctest::Approx(-1.0).epsilon(0.0001));
    CHECK(rot.e_11 == doctest::Approx(0.0).epsilon(0.0001));
}



TEST_CASE("make_rotation_mat2 - Negative Winkel (Rotation gegen Uhrzeigersinn)")
{
    double phi = -3.141592653589793 / 2.0; // -90°
    buw::Mat2 rot = buw::make_rotation_mat2(phi);

    buw::Vec2 v{1.0f, 0.0f};
    buw::Vec2 result = rot * v;

    // Rotation von (1,0) um -90° ergibt (0,-1)
    CHECK(result.x == doctest::Approx(0.0f).epsilon(0.0001));
    CHECK(result.y == doctest::Approx(-1.0f).epsilon(0.0001));
}


int main(int argc, char *argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
