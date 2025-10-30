#pragma once

#include "figure.h"

namespace figure {

class Square: public Figure {
  private:
    Point* points; 
  public:
    Square();
    Square(Point p1, Point p2, Point p3, Point p4);
    Square(const Square& other);
    ~Square();

    Square& operator=(const Square& other);

    Point Center() const override;
    double Area() const override;
    operator double() const override;


  friend bool operator==(const Square& first, const Square& second);
  friend bool operator!=(const Square& first, const Square& second);
  friend std::ostream& operator<<(std::ostream& os, const Square& r);
  friend std::istream& operator>>(std::istream& in, Square& r);
};
    bool operator==(const Square& first, const Square& second);
    bool operator!=(const Square& first, const Square& second);
    std::ostream& operator<<(std::ostream& os, const Square& r);
    std::istream& operator>>(std::istream& in, Square& r);
} // namespace figure