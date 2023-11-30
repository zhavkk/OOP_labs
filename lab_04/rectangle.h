#pragma once
#include <iostream>
#include "calculations.h"
#include "figure.h"
#include <vector>

template <typename Type>
class Rectangle : public Figure{
    public:
        size_t _size;
        std::vector<std::pair<Type,Type>> points;
        Rectangle(){
            _size=4;
            points={{0,0},{0,0},{0,0},{0,0}};
        }
        Rectangle(std::vector<std::pair<Type,Type>> & p){
            _size=4;
            points=p;
        }
        ~Rectangle(){
            _size=0;
            points={};
        }
        Rectangle<Type>& operator=(const Rectangle<Type>& other);
        Rectangle<Type>& operator=(Rectangle<Type>&& other);
        operator double() const override;
};

template<typename Type>
inline std::ostream &operator<<(std::ostream &os, const Rectangle<Type> &p){
    for(size_t i{0};i<4;++i){
        os<<i+1<<":("<<p.points[i].first<<","<<p.points[i].second <<")\n";
    }
    return os;
}

template<typename Type>
inline std::istream &operator>>(std::istream &is,Rectangle<Type> &p){
    for(size_t i{0};i<4;++i){
        std::cout<<"Vvedite first point";
        is>>p.points[i].first;
        std::cout<<"Vvedite second point";
        is>>p.points[i].second;
    }
    return is;
}

template<typename Type>
inline bool operator==(const Rectangle<Type> &f,const Rectangle<Type> &s){
    for(size_t i{0};i<4;++i){
        if(f.points[i]!=s.points[i]){
            return false;
        }

    }
    return true;
    
}       

template<typename Type>
inline Rectangle<Type> &Rectangle<Type>::operator=(const Rectangle<Type> &other ){
    points=other.points;
    _size=other._size;
    return *this;
}

template<typename Type>
inline Rectangle<Type>& Rectangle<Type>::operator=( Rectangle<Type> &&other){
    points=std::move(other.points);
    _size=std::move(other._size);
    return *this;
}
template<typename Type>
inline Rectangle<Type>::operator double() const{
    return surf<Rectangle<Type>,Type>(*this);
}
