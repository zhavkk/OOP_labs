#include "rectangle.h"
#include <exception>
#include <cmath>

Rectangle::Rectangle(){
    x_kords={0.0,0.0,0.0,0.0};
    y_kords={0.0,0.0,0.0,0.0};
    mid_x=0.0;
    mid_y=0.0;
    surface=0;

}

Rectangle::Rectangle(std::vector<double> &x,std::vector<double> &y){
    mid_x=0;
    mid_y=0;
    if(x_kords.size()!=4){
        x_kords.resize(4);
    }
    if(y_kords.size()!=4){
        y_kords.resize(4);
    }
    for (int i = 0; i < 4; ++i)
    {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    double xA = x_kords[0];
    double yA = y_kords[0];
    double xB = x_kords[1];
    double yB = y_kords[1];
    double xC = x_kords[2];
    double yC = y_kords[2];
    double xD = x_kords[3];
    double yD = y_kords[3];

    double length = std::abs(std::sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA)));
    double width = std::abs(std::sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB)));
    mid_x = (xA + xC) / 2;
    mid_y = (yA + yC) / 2;

    surface=length*width;
    

}

Rectangle::~Rectangle(){
    x_kords={};
    y_kords={};
    mid_x=0;
    mid_y=0;
    surface=0;
}

bool Rectangle::operator==(Rectangle &other) const {
    if(surface==other.surface){
        return true;
    }
    else{
        return false;

    }
}
Rectangle &Rectangle::operator=(Rectangle &other){
    x_kords=other.x_kords;
    y_kords=other.y_kords;
    mid_x=other.mid_x;
    mid_y=other.mid_y;
    surface=other.surface;
    return *this;
}
Rectangle &Rectangle::operator=(Rectangle &&other){
    x_kords=std::move(other.x_kords);
    y_kords=std::move(other.y_kords);
    mid_x=std::move(other.mid_x);
    mid_y=std::move(other.mid_y);
    surface=std::move(other.surface);
    return *this;

}