#pragma once
#include <string>
#include <iostream>
#include <utility>
class Figure{

    public:
        Figure();
        virtual ~Figure();
        virtual std::pair<double,double> center() const = 0;
        virtual double ploshad() const = 0;
        virtual explicit operator double() const = 0;
                
};