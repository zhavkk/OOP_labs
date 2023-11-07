#include "array.h"
Array::Array(){
    _size=10;
    _figures=new Figure *[_size];
    for(size_t i{0};i<_size;++i){
        _figures[i]=nullptr;

    }

    
}
Array::Array(size_t size){
    _size=size;
    _figures=new Figure *[_size];
    for(size_t i{0};i<_size;++i){
        _figures[i]=nullptr;

    }

}
Array::~Array() {
    for (size_t i = 0; i < _size; ++i) {
        if (_figures[i] != nullptr) {
            delete _figures[i];
            _figures[i] = nullptr;
        }
    }
    delete[] _figures;
    _figures = nullptr;
}

Figure *Array::operator[](size_t index){
    return _figures[index];
}

void Array::del_figure(size_t index){
    delete _figures[index];
    _figures[index]=nullptr;
}

void Array::changefigures(size_t index, Figure *other){
    if(_figures[index]!=nullptr){
        _figures[index]=nullptr;
    }
    _figures[index]=other;
}

double Array::avg_ploshad(){
    double summary=0;
    for(size_t i{0};i<_size;++i){
        summary+=(double)*_figures[i];
    }

    return summary;
}