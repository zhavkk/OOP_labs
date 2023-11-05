#pragma once

#include <iostream>
#include "figure.h"
#include <utility>
#include <vector>
class Triangle : public Figure{

    friend std::ostream operator<<(std::ostream& os,Triangle& p);
    friend std::istream operator>>(std::istream& is,Triangle& p);
    
    public:
        Triangle();
        Triangle(std::vector<double> &x,std::vector<double> &y);
        ~Triangle();

        bool operator==(Triangle &other) const;
        Triangle &operator=(Triangle &other);
        Triangle &operator=(Triangle &&other);

        



        double ploshad() const override{
            return surface;
        }

        std::pair<double,double> center() const override{
            return std::make_pair(mid_x, mid_y);  
        }

        operator double() const override{
            return surface;
        }


    private:

        std::vector<double> x_kords;
        std::vector<double> y_kords;
        double mid_x;
        double mid_y;
        double surface;


    b


};

    inline std::ostream operator<<(std::ostream& os,Triangle& p){
        for(int i = 0 ; i<3;++i){
            os<<"Koords  "<<i+1<<": ( "<< p.x_kords[i]<<" , "<<p.y_kords[i]<<")\n";
        }
        return os;


    }

    inline std::istream operator>>(std::istream& is,Triangle&p){
        double x,y;
        std::vector<double> x_k(3),y_k(3);
        for(int i=0;i<3;++i){
            std::cout<<"Vvedite koords "<<i+1<<":\n";
            std::cout<<"x: ";
            is>>x;
            std::cout<<"y: ";
            is>>y;
            x_k[i]=x;
            y_k[i]=y;
        }
        p=Triangle(x_k,y_k);
        return is;
        
    }