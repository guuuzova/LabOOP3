#include <iostream>

#include "vector.h"
#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

int main() {
    vector::Vector Figures;
    int n;
    std::cout << "Enter number of figure" << std::endl;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string figure;
        std::cout << "Enter type of figure" << std::endl;
        std::cin >> figure;

        if (figure == "rectangle") {
            figure::Rectangle* r = new figure::Rectangle();
            std::cin >> *r;
            Figures.PushBack(r);
        } else if (figure == "square") {
            figure::Square* s = new figure::Square();
            std::cin >> *s;
            Figures.PushBack(s);
        } else if (figure == "triangle") {
            figure::Triangle* t = new figure::Triangle();
            std::cin >> *t;
            Figures.PushBack(t);
        }
    }

    for (int i = 0; i < Figures.Size(); ++i) {
        std::cout << "Figure " << i << std::endl;
        std::cout << "Area " << static_cast<double>(*Figures[i]) << std::endl;
        std::cout << "Center " << Figures[i]->Center() << std::endl;
    }

    std::cout << "Total area:" << std::endl;
    double area = 0;

    for (int i = 0; i < Figures.Size(); ++i) {
        area += static_cast<double>(*Figures[i]);
    }
    std::cout << area << std::endl;

    int index;
    std::cout << "Enter index for erase" << std::endl;
    std::cin >> index;
    if (index >= 0 && index < Figures.Size()) {
        Figures.Erase(index);
    } else {
        std::cout << "Invalid index";
    }

    return 0;
    
}