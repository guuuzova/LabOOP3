#pragma once

#include "figure.h"

namespace figure {

class Rectangle: public Figure {
  private:
    Point* points; 
  public:
    Rectangle();
    Rectangle(Point p1, Point p2, Point p3, Point p4);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    Rectangle& operator=(const Rectangle& other);

    Point Center() const override;
    double Area() const override;
    operator double() const override;

  friend bool operator==(const Rectangle& first, const Rectangle& second);
  friend bool operator!=(const Rectangle& first, const Rectangle& second);
  friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
  friend std::istream& operator>>(std::istream& in, Rectangle& r);
};
    bool operator==(const Rectangle& first, const Rectangle& second);
    bool operator!=(const Rectangle& first, const Rectangle& second);
    std::ostream& operator<<(std::ostream& os, const Rectangle& r);
    std::istream& operator>>(std::istream& in, Rectangle& r);

} // namespace figure