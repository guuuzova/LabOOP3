#include "figure.h"

namespace figure {

Point::Point(double x, double y): x(x), y(y) {} 

bool operator==(const Point& first, const Point& second) {
    bool x = std::fabs(first.x - second.x) < EPS;
    bool y = std::fabs(first.y - second.y) < EPS;
    return (x && y);
}

bool operator!=(const Point& first, const Point& second) {
    return !(first == second);
}

double Distance(const Point& first, const Point& second) {
    return std::sqrt(std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2));
}
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.x >> point.y;
    return in;
}
}