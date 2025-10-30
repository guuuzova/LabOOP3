#include "triangle.h"

namespace figure {
    Triangle::Triangle(): Triangle(Point(0, 0), Point(2,0), Point(1, std::sqrt(3))) {}

    Triangle::Triangle(Point p1, Point p2, Point p3) {
        points = new Point[TRIANGLE_ANGLES]{p1, p2, p3};
    }

    Triangle::Triangle(const Triangle& other) {
        points = new Point[TRIANGLE_ANGLES];
        for( int i = 0; i < TRIANGLE_ANGLES; ++i) {
            points[i] = Point(other.points[i].x , other.points[i].y);
        }
    }

    Triangle& Triangle::operator=(const Triangle& other) {
        if (&other == this) {
            return *this;
        }
        for (int i = 0; i < TRIANGLE_ANGLES; ++i) {
            points[i] = other.points[i];
        }
        return *this;
    }

    Point Triangle::Center() const {
        return Point ((points[0].x + points[1].x + points[2].x) / 3, (points[0].y + points[1].y + points[2].y) / 3);;
    }

    double Triangle::Area() const {
        double area = std::pow(Distance(points[0], points[1]), 2) * (std::sqrt(3) / 4);
        return area;
    }

    Triangle::operator double() const {
        return Area();
    }

    Triangle::~Triangle() {
        delete[] points;
    }

    bool operator==(const Triangle& first, const Triangle& second) {
        double first_side = Distance(first.points[0], first.points[1]);
        double second_side = Distance(second.points[0], second.points[1]);
        return (first_side == second_side && first.Area() - second.Area() < EPS);
    }

    bool operator!=(const Triangle& first, const Triangle& second) {
        return !(first == second);
    }

    std::ostream& operator<<(std::ostream& os, const Triangle& r) {
        os << "[";
        for (size_t i = 0; i != TRIANGLE_ANGLES; ++i) {
            os << r.points[i];
        }
        os << "]" << std::endl;
        return os;
    }
    std::istream& operator>>(std::istream& in, Triangle& r) {
        Point input_points[TRIANGLE_ANGLES];
        for (size_t i = 0; i != TRIANGLE_ANGLES; ++i) {
            in >> input_points[i];
        }
        
        Triangle tmp(input_points[0], input_points[1], input_points[2]);
        r = tmp;
        return in;
    }
}