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
TEST_CASE("vec2  Addition")
{
  buw::Vec2 b{3.2f, 1.2f};
  CHECK(a.x == 6.4f);
  CHECK(a.y == 2.4f);

  buw::Vec2 b{-3.2f, -1.2f};
  b+=b;
  CHECK(a.x == -6.4f);
  CHECK(a.y == -2.4f);

  buw::Vec2 b{1, -1};
  CHECK(a.x == 2);
  CHECK(a.y == -2);
}

int main(int argc, char *argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
