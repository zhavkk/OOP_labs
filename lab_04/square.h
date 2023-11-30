#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "figure.h"

template <typename Type>
class Square : public Figure{
    public:
        size_t _size;
        std::vector<std::pair<Type,Type>> points;
        Square(){
            _size=4;
            points={{0,0},{0,0},{0,0},{0,0}};
        }
        Square(std::vector<std::pair<Type,Type>> &p){
            _size=4;
            points=p;
        }
        ~Square(){
            _size=0;
            points={};
        }
        Square<Type> &operator=(const Square<Type> &other);
        Square<Type> &operator=(const Square<Type> &&other);
        operator double() const override; 
};

template<typename Type>
inline std::ostream &operator<<(std::ostream &os, const Square<Type> &p){
    for(size_t i{0};i<4;++i){
        os<<i+1<<":("<<p.points[i].first<<","<<p.points[i].second <<")\n";
    }
    return os;
}

template<typename Type>
inline std::istream &operator>>(std::istream &is,Square<Type> &p){
    for(size_t i{0};i<4;++i){
        std::cout<<"Vvedite first point";
        is>>p.points[i].first;
        std::cout<<"Vvedite second point";
        is>>p.points[i].second;
    }
    return is;
}

template<typename Type>
inline bool operator==(const Square<Type> &f,const Square<Type> &s){
    for(size_t i{0};i<4;++i){
        if(f.points[i]!=s.points[i]){
            return false;
        }

    }
    return true;
    
}       

template<typename Type>
inline Square<Type> &Square<Type>::operator=(const Square<Type> &other ){
    points=other.points;
    _size=other._size;
    return *this;
}

template<typename Type>
inline Square<Type> &Square<Type>::operator=(const Square<Type> &&other){
    points=std::move(other.points);
    _size=std::move(other._size);
    return *this;
}
template<typename Type>
inline Square<Type>::operator double() const{
    return surf<Square<Type>,Type>(*this);
}

