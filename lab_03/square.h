#pragma once
#include <iostream>
#include "figure.h"
#include <utility>
#include <vector>

class Square : public Figure{



    public:
        Square();
        Square(std::vector<double> &x,std::vector<double> &y);
        ~Square();
        bool operator==(Square &other) const;
        Square &operator=(Square &other);
        Square &operator=(Square &&other);
        friend std::ostream &operator<<(std::ostream& os, const Square&);
        friend std::istream &operator>>(std::istream& is, Square&);

        double ploshad() const override{
            return surface;
        }
        std::pair<double,double> center() const override{

            return std::make_pair(mid_x,mid_y);
        }
        operator double() const override{
            return surface;
        }



    protected:
        std::vector<double> x_kords;
        std::vector<double> y_kords;
        double surface;
        double mid_x;
        double mid_y;


};
inline std::ostream &operator<<(std::ostream& os, const Square& p){
    for(int i = 0; i<4;++i){
        os<<"Koords :"<<i+1<<"( : "<<p.x_kords[i]<<","<<p.y_kords[i]<<" )\n";

    }
    return os;

}

inline std::istream &operator>>(std::istream& is,Square&p){
    std::vector<double> x_k(4),y_k(4);
    double x,y;
    for(int i=0;i<4;++i){
        std::cout<<"Vvedite koords"<<i+1<<":\n";
        std::cout<<"x: ";
        is>>x;
        std::cout<<"y: ";
        is>>y;
        x_k[i]=x;
        y_k[i]=y;
    }
    p=Square(x_k,y_k);
    return is;
}   