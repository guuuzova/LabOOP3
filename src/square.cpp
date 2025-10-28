#include "square.h"

namespace figure {
Square::Square(): Square(Point(0, 0), Point(0,1), Point(1, 1), Point(1, 0)) {}

Square::Square(Point p1, Point p2, Point p3, Point p4) {
    points = new Point[SQUARE_ANGLES]{p1, p2, p3, p4};
}

Square::Square(const Square& other) {
    points = new Point[SQUARE_ANGLES];
    for( int i = 0; i < SQUARE_ANGLES; ++i) {
        points[i] = Point(other.points[i].x , other.points[i].y);
    }
}

Square& Square::operator=(const Square& other) {
    if (&other == this) {
        return *this;
    }
    for (int i = 0; i < SQUARE_ANGLES; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

Point Square::Center() const {
    return Point((points[0].x + points[2].x) / 2, (points[0].y + points[2].y) / 2);
}

double Square::Area() const {
    double area = std::pow(Distance(points[0], points[1]), 2);
    return area;
}

Square::operator double() const {
    return Area();
}

Square::~Square() {
    delete[] points;
}

bool operator==(const Square& first, const Square& second) {
    double first_side = Distance(first.points[0], first.points[1]);
    double second_side = Distance(second.points[0], second.points[1]);
    return (first_side == second_side && first.Area() - second.Area() < EPS);
}

bool operator!=(const Square& first, const Square& second) {
    return !(first == second);
}

std::ostream& operator<<(std::ostream& os, const Square& r) {
    os << "[";
    for (size_t i = 0; i != SQUARE_ANGLES; ++i) {
        os << r.points[i];
    }
    os << "]" << std::endl;
    return os;
}
std::istream& operator>>(std::istream& in, Square& r) {
    Point input_points[SQUARE_ANGLES];
    for (size_t i = 0; i != SQUARE_ANGLES; ++i) {
        in >> input_points[i];
    }
    Square tmp(input_points[0], input_points[1], input_points[2], input_points[3]);
    r = tmp;       
    return in;
}
}