#include "constructors.hxx"
#define _USE_MATH_DEFINES

#include <stdexcept>
#include <iostream>
#include <cmath>

Posn::Posn(double x, double y)
        :x(x)
        ,y(y)
{
    if(std::isnan(x))
        throw std::invalid_argument("Posn requires a valid number as x coordinate.");
    if(std::isnan(y))
        throw std::invalid_argument("Posn requires a valid number as y coordinate.");
}

Posn::Posn()
        : Posn(0, 0)
{ }

double
Posn::distance_to(Posn other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

std::ostream&
operator<<(std::ostream& out, Posn p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

Circle::Circle(double r, Posn c)
        : radius(r)
        , center(c)
{
    if (r > 0) return;

    throw std::invalid_argument("Circle requires a positive radius.");
}

Circle::Circle(double radius, double x, double y)
        : Circle(radius, {x, y})
{
}

double
Circle::area() const
{
    return radius * radius * M_PI;
}

bool
Circle::overlaps(Circle other) const
{
    return radius + other.radius > center.distance_to(other.center);
}
