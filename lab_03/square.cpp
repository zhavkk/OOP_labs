#include "square.h"
#include <exception>
#include <cmath>
Square::Square(){
    x_kords={0.0,0.0,0.0,0.0};
    y_kords={0.0,0.0,0.0,0.0};
    mid_x=0.0;
    mid_y=0.0;
    surface=0;

}

Square::Square(std::vector<double> &x,std::vector<double> &y){
    mid_x=0.0;
    mid_y=0.0;
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
    mid_x=mid_x/4;
    mid_y=mid_y/4;
    double x1 = x_kords[0];
    double y1 = y_kords[0];
    double x2 = x_kords[1];
    double y2 = y_kords[1];

    // Вычислите расстояние между вершинами A и B
    double side = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    surface=side*side;

}

Square::~Square(){
    x_kords={};
    y_kords={};
    mid_x=0;
    mid_y=0;
    surface=0;
}

bool Square::operator==(Square &other) const{
    if(surface==other.surface){
        return true;
    }
    else{
        return false;

    }
}
Square &Square::operator=(Square &other){
    x_kords=other.x_kords;
    y_kords=other.y_kords;
    mid_x=other.mid_x;
    mid_y=other.mid_y;
    surface=other.surface;
    return *this;
}
Square &Square::operator=(Square &&other){
    x_kords=std::move(other.x_kords);
    y_kords=std::move(other.y_kords);
    mid_x=std::move(other.mid_x);
    mid_y=std::move(other.mid_y);
    surface=std::move(other.surface);
    return *this;

}

