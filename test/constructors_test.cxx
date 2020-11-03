#include "constructors.hxx"

#include <catch.hxx>

#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>


TEST_CASE("Default construct a Posn")
{
    Posn origin;
    CHECK( origin.x == 0 );
    CHECK( origin.y == 0 );
}

TEST_CASE("Posn::distance_to(Posn other) const")
{
    Posn with_numbers1 {10,7};
    Posn with_numbers2 {6,4};

    CHECK(with_numbers1.distance_to(with_numbers2) == 5);
}

TEST_CASE("Posn::Posn throws given bad x and y")
{
    CHECK_THROWS_AS(Posn(NAN, NAN), std::invalid_argument);
    CHECK_THROWS_AS(Posn(NAN, 3), std::invalid_argument);
    CHECK_THROWS_AS(Posn(0, NAN), std::invalid_argument);
}

TEST_CASE("Circle::area() const")
{
    Posn   questionable;
    Circle less_questionable{1, questionable};

    CHECK(less_questionable.area() == M_PI);
}

TEST_CASE("Circle::Circle throws given bad radius")
{
    CHECK_THROWS_AS(Circle(-4, 0, 9), std::invalid_argument);
    CHECK_THROWS_AS(Circle(0, 0, 9), std::invalid_argument);
    CHECK_THROWS_AS(Circle(NAN, {0, 9}), std::invalid_argument);
}
