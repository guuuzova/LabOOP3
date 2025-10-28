#pragma once

#include <iostream>
#include <cmath>

namespace figure {
constexpr double EPS = 1e-9;
const int8_t TRIANGLE_ANGLES = 3;
const int8_t SQUARE_ANGLES = 4;
const int8_t RECTANGLE_ANGLES = 4;

class Point {
    public:
    double x = 0.0;
    double y = 0.0;
    Point() = default;
    Point(double x, double y);
};

bool operator==(const Point& first, const Point& second);
bool operator!=(const Point& first, const Point& second);


class Figure {
    public:
    virtual Point Center() const = 0;
    virtual double Area() const  = 0;
    virtual operator double() const = 0;
    virtual ~Figure() = default;
};

double Distance(const Point& first, const Point& second);
std::ostream& operator<<(std::ostream& os, const Point& point);
std::istream& operator>>(std::istream& in, Point& point);
}