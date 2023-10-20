#include "Eleven.h"
#include <cstring>
#include <cmath>
//konstruktori
Eleven::Eleven(){
     _array=new unsigned char;
     *_array={'0'};
     _size=1;
}

Eleven::Eleven(const std::size_t &size,unsigned char t){
    if (!((t >= '0' && t <= '9') || (t!='A'))) {
        throw std::invalid_argument("character isn't an eleven-based digit");
    }

    _size=size;
    _array = new unsigned char [_size];
    for(std::size_t i{0};i<_size;++i){
        _array[i]=t;
    }
    

}

Eleven::Eleven(const std::initializer_list<unsigned char>& t) {
    _size = t.size();
    _array = new unsigned char[_size];

    int i = 0;
    for (unsigned char elem : t) {
        if (!((elem >= '0' && elem <= '9') || (elem!='A'))) {
            delete[] _array;
            throw std::invalid_argument("invalid character in initializer_list");
        }
        _array[i++] = elem;
    }
}

Eleven::Eleven(const std::string &t){
    _size=t.size();
    _array=new unsigned char[_size];
    std::size_t i = _size - 1;
    for (unsigned char elem : t) {
        if (!((elem >= '0' && elem <= '9') || (elem =='A'))) {
            throw std::invalid_argument("invalid character");
        }
        _array[i--]=elem;
    }
}
Eleven::Eleven(const Eleven& other){
    _size=other._size;
    _array = new unsigned char[_size];

    for(std::size_t i{0};i<_size;++i){
        _array[i]=other._array[i];
    }

}

Eleven::Eleven(Eleven&& other) noexcept{
    _size=other._size;
    _array=other._array;

    other._size=0;
    other._array={nullptr};


}

Eleven::~Eleven(){
    _size=0;

    delete _array;
    _array={nullptr};
}


std::string Eleven::get_string(){
    std::string result="";
    int k=_size;
    for(int i=0;i<k;++i){
        result+=_array[i];
    }
    return result;

}
size_t Eleven::get_size(){
    return _size;
}

unsigned char * Eleven::get_array(){
    return _array;
}

unsigned char to_char(int n) {
    if (n < 10) {
        return n + '0';
    }
    else {
        return n - 10 + 'A';
    }
}

int to_int(unsigned char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }
}

 // from 11 to 10 
 int Eleven::translate_to_10(){
     to_10 = 0;
     for (int q = 0; q < _size; q++) {
         int digit = to_int(_array[q]); //  Преобразуем символ в цифру

         to_10 = to_10 * 11 + digit;
     }
     return to_10;
 }

// сложение 
std::string Eleven::plus(const Eleven& other)
{
    int res = this -> to_10 + other.to_10;
    std::string result;
    std::string rev_result;
    int w = res;
    char dop;

    while (w > 0){
        if (w % 11 == 10){
            result.append("A");
        }
        if ((w % 11 != 10)){
            dop = w % 11;
            result.append(std::to_string(dop));
        }
        w /= 11;
    }

    for (int q = result.length() - 1; q >= 0; q--){
        rev_result += result[q];
    }

    return rev_result;
}

// вычитание
std::string Eleven::minus(const Eleven& other)
{
    std::string result;
    std::string rev_result;

    if (this -> to_10 < other.to_10){
        return "negative number";
    }

    if (this -> to_10 == other.to_10){
        return "0";
    }

    if (this -> to_10 > other.to_10){
        int res = this -> to_10 - other.to_10;
        int w = res;
        char dop;

        while (w > 0){
            if (w % 11 == 10){
                result.append("A");
            }
            if ((w % 11 != 10)){
                dop = w % 11;
                result.append(std::to_string(dop));
            }
            w /= 11;
        }

        for (int q = result.length() - 1; q >= 0; q--){
            rev_result += result[q];
        }
    }
        return rev_result;
}

Eleven Eleven::copy(){
    Eleven result;
    size_t rev=_size-1;
    for(size_t q = 0 ; q<_size;++q){
        result._array[rev]=_array[q];
        rev--;
    }

    return result;
}

// сравнение >
std::string Eleven::bigger(const Eleven& other)
{
    if (this -> to_10 > other.to_10){
        return "true";
    }

    else{
        return "false";
    }
}

// сравнение <
std::string Eleven::smaller(const Eleven& other)
{
    if (this -> to_10 < other.to_10){
        return "true";
    }

    else{
        return "false";
    }
}

// сравнение =
std::string Eleven::equall(const Eleven& other)
{
    if (this -> to_10 == other.to_10){
        return "true";
    }

    else{
        return "false";
    }
}