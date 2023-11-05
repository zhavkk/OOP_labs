#include <iostream>
#include "array.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

int main(){

    std::vector<double> tria_x{0,
                               sqrt(6250 + 1250 * sqrt(5)),
                               -sqrt(6250 + 1250 * sqrt(5))};
    std::vector<double> tria_y{100,
                               -25 + 25 * sqrt(5),
                               -25 + 25 * sqrt(5)};

    std::vector<double> rect_x{2,
                              1,
                              -1,
                              -2
                                };
    std::vector<double> rect_y{0,
                              sqrt(3),
                              sqrt(3),
                              0};
                              

    std::vector<double> sq_x{sqrt(2),
                                1,
                                0,
                                1};

    std::vector<double> sq_y{0,
                                1,
                                sqrt(2),
                                -1};

    Triangle p = Triangle(tria_x, tria_y);
    Rectangle h = Rectangle(rect_x, rect_y);
    Square l = Square(sq_x, sq_y);

    // std::cin >> p;
    // std::cout << p;
    // point k = h.mid_dot();
    // std::cout << k.x << " " << k.y;
    // std::cout << (double)l;

    Array q = Array(3);
    q.change(0, &p);
    q.change(1, &h);
    q.change(2, &l);

    for (int i = 0; i < 3; ++i)
    {
        const Figure *fig = q[i];
        if (q[i] == nullptr)
        {
            std::cout << "The figure has been deleted" << std::endl;
        }
        else if (typeid(p) == typeid(*fig))
        {
            std::cout << *(Triangle *)q[i];
        }
        else if (typeid(h) == typeid(*fig))
        {
            std::cout << *(Rectangle *)q[i];
        }
        else if (typeid(l) == typeid(*fig))
        {
            std::cout << *(Square *)q[i];
        }
    }

    std::cout << "\n\n";

    Triangle ex = Triangle();
    ex = p;
    std::cout << ex;
}
