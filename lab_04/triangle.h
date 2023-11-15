#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "figure.h"

template <typename Type>
class Triangle : public Figure{
    public:
        size_t _size;
        Type surf;
        std::vector<std::pair<Type,Type>> points;
        Triangle(){
            _size=3;
            points=({{0,0},{0,0},{0,0}});
        }
        Triangle(std::vector<std::pair<Type,Type>> &p){
            _size=3;
            points=p;
        }
        ~Triangle(){
            _size=0;
            points={};
        }
        Triangle<Type> &operator=(const Triangle<Type> &other);
        Triangle<Type> &operator=(const Triangle<Type> &&other);
        operator double() const override; 
};

template<typename Type>
inline std::ostream &operator<<(std::ostream &os, const Triangle<Type> &p){
    for(size_t i{0};i<3;++i){
        os<<i+1<<":("<<p.points[i].first<<","<<p.points[i].second <<")\n";
    }
    return os;
}

template<typename Type>
inline std::istream &operator>>(std::istream &is,Triangle<Type> &p){
    for(size_t i{0};i<3;++i){
        std::cout<<"Vvedite first point";
        is>>p.points[i].first;
        std::cout<<"Vvedite second point";
        is>>p.points[i].second;
    }
    return is;
}

template<typename Type>
inline bool operator==(const Triangle<Type> &f,const Triangle<Type> &s){
    
}       

template<typename Type>
inline Triangle<Type> &Triangle<Type>::operator=(const Triangle<Type> &other ){
    // points=orther.points;
    // _size=other._size;
    // return *this;
}

template<typename Type>
inline Triangle<Type> &Triangle<Type>::operator=(const Triangle<Type> &&other){
    // points=std::move(other.points);
    // _size=std::move(other._size);
    // return *this;
}
template<typename Type>
inline Triangle<Type> Triangle<Type>::operator double() const{
    
}

