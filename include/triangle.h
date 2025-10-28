#pragma once

#include "figure.h"

namespace figure {

class Triangle: public Figure {
  private:
    Point* points; 
  public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    Triangle(const Triangle& other);
    ~Triangle();

    Triangle& operator=(const Triangle& other);
    
    bool operator==(const Point& other);
    bool operator!=(const Point& other);

    Point Center() const override;
    double Area() const override;
    operator double() const override;


  friend bool operator==(const Triangle& first, const Triangle& second);
  friend bool operator!=(const Triangle& first, const Triangle& second);
  friend std::ostream& operator<<(std::ostream& os, const Triangle& r);
  friend std::istream& operator>>(std::istream& in, Triangle& r);
};
    bool operator==(const Triangle& first, const Triangle& second);
    bool operator!=(const Triangle& first, const Triangle& second);
    std::ostream& operator<<(std::ostream& os, const Triangle& r);
    std::istream& operator>>(std::istream& in, Triangle& r);
} // namespace figure