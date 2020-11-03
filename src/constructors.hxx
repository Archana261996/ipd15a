#pragma once

#include <iostream>
#define _USE_MATH_DEFINES

// Represents a point on the 2-D Euclidean plane.
struct Posn
{
    double x, y;

    // Constructs the `Posn` with the given coordinates.
    Posn(double x, double y);

    // Default constructs the origin.
    Posn();

    // Computes the distance between two `Posn`s
    double distance_to(Posn other) const;
};

// Stream insertion for `Posn`.
std::ostream&
operator<<(std::ostream& out, Posn p);

// Represents a circle on the 2-D Euclidean plane.
struct Circle
{
    double radius;
    Posn center;

    // Constructs a circle with the given radius and center.
    //
    // PRECONDITION: radius > 0
    Circle(double radius, Posn center);

    // Constructs a circle with the given radius, center x, and center y.
    //
    // PRECONDITION: radius > 0
    Circle(double radius, double x, double y);

    // Computes the area of this circle.
    double area() const;

    // Determines whether two circles overlap.
    bool overlaps(Circle other) const;
};
