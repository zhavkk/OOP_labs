#pragma once
#include <string>
#include <iostream>
#include <utility>
class Figure{
    protected:
        Figure()=default;

    public:
        virtual ~Figure()=default;
        virtual std::pair<double,double> center() const = 0;
        virtual double ploshad() const = 0;
        virtual explicit operator double() const = 0;
                
};