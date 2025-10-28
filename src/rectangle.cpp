#include "rectangle.h"

namespace figure {
    Rectangle::Rectangle(): Rectangle(Point(0, 0), Point(0,1), Point(1, 1), Point(1, 0)) {}

    Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
        points = new Point[RECTANGLE_ANGLES] {p1, p2, p3, p4};
    }

    Rectangle::Rectangle(const Rectangle& other) {
        points = new Point[RECTANGLE_ANGLES];
        for( int i = 0; i < RECTANGLE_ANGLES; ++i) {
            points[i] = Point(other.points[i].x , other.points[i].y);
        }
    }

    Rectangle& Rectangle::operator=(const Rectangle& other) {
        if (&other == this) {
            return *this;
        }
        for (int i = 0; i < RECTANGLE_ANGLES; ++i) {
            points[i] = other.points[i];
        }
        return *this;
    }

    Point Rectangle::Center() const {
        return Point ((points[0].x + points[2].x) / 2.0, (points[0].y + points[2].y) / 2.0);
    }

    double Rectangle::Area() const {
        double area = Distance(points[0], points[1]) * Distance(points[1], points[2]);
        return area;
    }

    Rectangle::operator double() const {
        return Area();
    }

    Rectangle::~Rectangle() {
        delete[] points;
    }

    bool operator==(const Rectangle& first, const Rectangle& second) {
        double first_side = Distance(first.points[0], first.points[1]);
        double second_side = Distance(second.points[0], second.points[1]);
        return (first_side == second_side && first.Area() - second.Area() < EPS);
    }

    bool operator!=(const Rectangle& first, const Rectangle& second) {
        return !(first == second);
    }

    std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
        os << "[";
        for (size_t i = 0; i != RECTANGLE_ANGLES; ++i) {
            os << r.points[i];
        }
        os << "]" << std::endl;
        return os;
    }
    std::istream& operator>>(std::istream& in, Rectangle& r) {
        Point input_points[RECTANGLE_ANGLES];
        for (size_t i = 0; i != RECTANGLE_ANGLES; ++i) {
            in >> input_points[i];
        }
        Rectangle tmp(input_points[0], input_points[1], input_points[2], input_points[3]);
        r = tmp;
        return in;
    }
}