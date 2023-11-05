#pragma once
#include <iostream>
#include "figure.h"
#include <utility>
#include <vector>
class Rectangle : public Figure{
    friend std::ostream operator<<(std::ostream &os,Rectangle &p);
    friend std::istream operator>>(std::istream &is,Rectangle &p);
    public:
        Rectangle();
        Rectangle(std::vector<double> &x,std::vector<double> &y);
        ~Rectangle();
        bool operator==(Rectangle &other);
        Rectangle &operator=(Rectangle &other);
        Rectangle &operator=(Rectangle &&other);
        
        std::pair<double,double> center() const override{
            std::make_pair(mid_x,mid_y);
        }

        double ploshad() const override{
            return surface;
        }
        operator double() const override{
            return surface;
        }

    
    private:
        double mid_x;
        double mid_y;
        double surface;
        std::vector<double> x_kords;
        std::vector<double> y_kords;

};

    inline std::ostream operator<<(std::ostream &os,Rectangle &p){
        for(size_t i{0};i<4;++i){
            os<<"Koords : "<<i+1<<"( "<<p.x_kords[i]<<","<<p.y_kords[i]<<")\n";
        }
        return os;
    }
    inline std::istream operator>>(std::istream &is,Rectangle &p){
        double x,y;
        std::vector<double> x_k(4),y_k(4);
        for(size_t i{0};i<4;++i){
            std::cout<<"Vvedite kords "<<i+1;<<":\n";
            std::cout<<"x : ";
            is>>x;
            std::cout<<"y : ";
            is>>y;
            x_k[i]=x;
            y_k[i]=y;

        }
        p=Rectangle(x_k,y_k);
        return is;
    }