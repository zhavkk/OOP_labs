#include <iostream>
#include "array.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include <cmath>

int main() {
    std::vector<double> tria_x{0.0, 10.0, 0.0};
    std::vector<double> tria_y{0.0, 0.0, 10.0};

    std::vector<double> rect_x{2, 1, 3, 4};
    std::vector<double> rect_y{0, 1, 2, 3};

    std::vector<double> sq_x{1, 2, 3, 4};
    std::vector<double> sq_y{0, 1, 2, 3};

    Triangle p = Triangle(tria_x, tria_y);
    Rectangle h = Rectangle(rect_x, rect_y);
    Square l = Square(sq_x, sq_y);

    Array q = Array(3);
    q.changefigures(0, new Triangle(tria_x, tria_y));
    q.changefigures(1, new Rectangle(rect_x, rect_y));
    q.changefigures(2, new Square(sq_x, sq_y));

    for (int i = 0; i < 3; ++i) {
        const Figure* fig = q[i];
        if (q[i] == nullptr) {
            std::cout << "The figure has been deleted" << std::endl;
        } else {
            std::cout << "Figure " << i + 1 << ":\n";
            std::cout << "Ploshad: " << fig->ploshad() << std::endl;
            std::pair<double, double> center = fig->center();
            std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        }
    }

    std::cout << std::endl;

    Triangle ex = Triangle();
    ex = p;
    std::cout << "Ploshad of ex: " << ex.ploshad() << std::endl;
    std::pair<double, double> ex_center = ex.center();
    std::cout << "Center of ex: (" << ex_center.first << ", " << ex_center.second << ")\n";

    return 0;
}
