#include "Eleven.h"
#include <cstring>
//konstruktori
void Eleven::resize(size_t size) {
    unsigned char* new_array = new unsigned char[size];

    std::memcpy( new_array, _array, size * sizeof(unsigned char));

    _size = size;
    delete [] _array;
    _array = new_array;
}

Eleven::Eleven(){
    // _array=new unsigned char;
    // *_array={'0'};
    // _size=1;
    _size=0;
    _array={nullptr};
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
}

//getteri

size_t Eleven::get_size(){
    return _size;
}

std::string Eleven::get_array(){
    std::string result;
    for (int i = _size - 1; i >= 0; --i) {
        result += _array[i];
    }
    return result;
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


Eleven Eleven::operator+(const Eleven &other) {
    const unsigned char *a, *b; // a > b
    size_t size_a, size_b;
    if (_size < other._size) {
        a = other._array;
        size_a = other._size;
        b = _array;
        size_b = _size;
    } else {
        b = other._array;
        a = _array;
        size_a = _size;
        size_b = other._size;
    }

    Eleven result = Eleven(size_a, '0');

    int remain = 0;
    for (int i = 0; i < size_b; ++i) {
        int val = to_int(a[i]) + to_int(b[i]) + remain;
        result._array[i] = to_char(val % 11);
        remain = val / 11;
    }
    for (int i = size_b; i < size_a; ++i) {
        int val = to_int(a[i]) + remain;
        result._array[i] = to_char(val % 11);
        remain = val / 11;
    }
    if (remain > 0) {
        result.resize(size_a + 1);
        result._array[result._size - 1] = to_char(remain);
    }

    return result;
}

Eleven Eleven::operator-(const Eleven &other){


    
}
// Eleven Eleven::operator-(const Eleven& other){
//     std::size_t maxsize=std::max(_size,other._size);
//     Eleven result(maxsize,0);
//     for(std::size_t i{0};i<maxsize;++i){
        
//     }
// }