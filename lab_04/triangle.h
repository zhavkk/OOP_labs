#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "figure.h"

template <typename Type>
class Triangle : public Figure{
    public:
        size_t _size;
        std::vector<std::pair<Type,Type>> points;
        Triangle(){
            _size=3;
            points=({{0,0},{0,0},{0,0}});
        }
        Triangle(std::vector<std::pair<Type,Type>> &p){
            _size=3;
            points=points(p);//?????????
        }
        ~Triangle(){
            _size=0;
            points={};
        }
        Triangle<Type> &operator=(const Triangle<Type> &other);
        Triangle<Type> &operator=(const Triangle<Type> &&other);
        operator double() const override; 
}

