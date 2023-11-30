#pragma once
#include <utility>
#include <cmath>

template <class C, typename Type>
std::pair<Type,Type> middle(C &figure){
    double size= figure._size;
    std::pair <Type,Type> tmp={0,0};
    for(std::pair <Type,Type> point: figure.points){
        tmp.first+=point.first;
        tmp.second+=point.second;

    }
    tmp.first/=size;
    tmp.second/=size;
    return tmp;
    
}

template <class C, typename Type>
Type surf(const C &figure){
    double size=figure._size;
    std::pair<Type, Type> fcoord = figure.points[0];
    std::pair<Type, Type> scoord = figure.points[1];
    Type lenght = std::sqrt(std::pow(fcoord.first - scoord.first, 2) + std::pow(fcoord.second - scoord.second, 2));
    return std::abs(size * lenght * lenght / (4 * std::tan(180/size)));

}