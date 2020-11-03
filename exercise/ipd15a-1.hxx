#pragma once

#include <iostream>

// Represents a point on the 2-D Euclidean plane.
struct Posn
{
    double x, y;
};

// Stream insertion for `Posn`.
std::ostream&
operator<<(std::ostream& out, Posn p);

// Represents a circle on the 2-D Euclidean plane.
struct Circle
{
    double radius;
    Posn center;
};

//Stream insertion for circle
std::ostream&
operator<<(std::ostream& out, Circle c);

