#include <iostream>
#include <vector>
#include <cmath>
#include "array.h"
#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

int main(){
    std::vector<std::pair<double,double>> points_3={{2.0,2.0},{4.0,4.0},{5.0,5.0}};
    Triangle<double> Tria(points_3);


    std::vector<std::pair<double, double>> points_41 = {{2.0, 2.0}, {4.0, 4.0}, {6.0, 6.0}, {4.0, 4.0}};
    std::vector<std::pair<double, double>> points_42 = {{2.0, 2.0}, {4.0, 4.0}, {5.0, 5.0}, {6.0, 6.0}};
    Square<double> Squ(points_42);
    Rectangle<double> Rect(points_41);

    std::cout<<(double)Squ<<std::endl<<(double)Rect<<std::endl<<(double)Tria<<std::endl;
    return 0;
}
