#include "triangle.h"
#include <exception>
#include <cmath>
Triangle::Triangle(){
    x_kords={0,0,0};
    y_kords={0,0,0};
    mid_x=0.0;
    mid_y=0.0;
    surface=0;

}



Triangle::Triangle(std::vector<double> &x,std::vector<double> &y){
    mid_x=0.0;
    mid_y=0.0;
    // if (x.size() != 3 || y.size() != 3) {
    //     x_kords.resize(3);
    //     y_kords.resize(3);
    //     throw std::invalid_argument("koords are wrong");

    // }
    if(x_kords.size()!=3){
        x_kords.resize(3);
    }
    if(y_kords.size()!=3){
        y_kords.resize(3);
    }
    for (int i = 0; i < 3; ++i)
    {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    mid_x=mid_x/3;
    mid_y=mid_y/3;
    double a = std::sqrt(std::pow((x[1] - x[0]),2) + std::pow((y[1] - y[0]),2));
    double b = std::sqrt(std::pow((x[2] - x[1]),2) + std::pow((y[2] - y[1]),2));
    double c = std::sqrt(std::pow((x[2] - x[0]),2) + std::pow((y[2] - y[0]),2));

    double p = (a + b + c) / 2;
    surface = std::sqrt(p * (p - a) * (p - b) * (p - c));
    
}

Triangle::~Triangle(){
    x_kords={};
    y_kords={};
    mid_x=0;
    mid_y=0;
    surface=0;
}
bool Triangle::operator==(Triangle &other) const {
    if(surface==other.surface){
        return true;
    }
    else{
        return false;
    }

}

Triangle &Triangle::operator=(Triangle &other){
    x_kords=other.x_kords;
    y_kords=other.y_kords;
    mid_x=other.mid_x;
    mid_y=other.mid_y;
    surface=other.surface;
    return *this;
}
Triangle &Triangle::operator=(Triangle &&other){
    x_kords=std::move(other.x_kords);
    y_kords=std::move(other.y_kords);
    mid_x=std::move(other.mid_x);
    mid_y=std::move(other.mid_y);
    surface=std::move(other.surface);
    return *this;
}