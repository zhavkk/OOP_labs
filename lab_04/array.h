#pragma once
#include <iostream>
#include <memory>
#include "figure.h"
#include "calculations.h"

template <class T>
class Array{
    private:
        size_t _size;
        std::shared_ptr<T[]> _arr;

    public:
        Array(){
            _size=0;
            _arr=nullptr;
        }
        Array(size_t size){
            _size=size;
            _arr=std::shared_ptr<T[]>(new T[_size]);
        }
        ~Array(){
            _size=0;
            _arr=nullptr;
        }

        T  &operator[](size_t index){
            return _arr[index];
        }
        double common_surf(){
            double sum=0;
            for(size_t i{0};i<_size;++i){
                sum+=(double)_arr[i];
            }
            return sum;
        }

};