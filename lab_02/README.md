# Лабораторная работа 2. Классы
## Автор: Жаворонков М.Н, группа М8О-212Б-22, вариант 9

Используя в качестве образца класс Array (см. ниже), реализовать динамические контейнеры с использованием динамического массива.
- Каждый класс должен быть разделен на интерфейс и реализацию.
- Самостоятельно определить необходимые типы, поля и дополнительные методы.
- Реализовать генерацию исключений в конструкторах и методах при необходимости (использовать стандартные исключения).
- Реализовать арифметические операции: сложение, вычитание, копирование
- Реализовать операции сравнения: (больше, меньше, равно).
- Арифметические операции с присваиванием должны быть реализованы как методы класса.

Создать класс Eleven для работы с беззнаковыми целыми одиннадцатиричными числами, используя для пред-
ставления числа массив из элементов типа unsigned char, каждый из которых является одиннадцатиричными
цифрой. Младшая цифра имеет меньший индекс (единицы – в нулевом элементе массива).
## Программы

### main.cpp
```
#include <iostream>
#include <string>
#include "Eleven.h"
#include <cmath>
int main(){
    std::string s1,s2;
    std::cout << "Enter 1 num: \n num1 = ";
    std::cin >> s1;

    std::cout << "Enter 2 num: \n num2 = ";
    std::cin >> s2;

    Eleven num1(s1);
    Eleven num2(s2);

    std::cout << "Number1 v 10 s.s = " << num1.translate_to_10() << '\n';
    std::cout << "Number2 v 10 s.s = " << num2.translate_to_10() << '\n' << '\n';

    std::cout << "a plus b = " << num1.plus(num2) << '\n';
    std::cout << "a minus b = " << num1.minus(num2) << '\n';
    std::cout << "a > b : " << num1.bigger(num2) << '\n';
    std::cout << "a < b : " << num1.smaller(num2) << '\n';
    std::cout << "a = b : " << num1.equall(num2) << '\n' << '\n';


    std::cout << std::endl << "length num1 : " << num1.get_size() << std::endl;
    std::cout << "length num2 : " << num2.get_size() << std::endl << std::endl;
    std::cout<<"ffff"<<std::endl;

    Eleven copy_num1 = num1.copy();
    std::cout<<"ffff"<<std::endl;
    std::cout << "Copy of num1:  " << copy_num1.get_array() << std::endl;
    Eleven copy_num2=num2.copy();
    std::cout<<"ffff"<<std::endl;
    std::cout<<"Copy of num2 : "<<copy_num2.get_array()<<std::endl;
    std::cout<<" GET STRING : "<<num1.get_string()<<std::endl;
    return 0;
}
```

### Eleven.h
```

#include <iostream>
#include <string>


class Eleven {
    public:
        Eleven(); //default constr
        Eleven(const std::size_t &size,unsigned char t=0);
        Eleven(const std::initializer_list<unsigned char> &t);
        Eleven(const std::string &t);
        Eleven(const Eleven& other);
        Eleven copy();

        Eleven(Eleven&& other) noexcept;
        ~Eleven() noexcept;

    
        size_t get_size();
        unsigned char* get_array();
        std::string get_string();
        int translate_to_10();
        // static std::string translate_to_11(int number);

        std::string plus(const Eleven& other);
        std::string minus(const Eleven& other);
        std::string bigger(const Eleven& other);
        std::string smaller(const Eleven& other);
        std::string equall(const Eleven& other);



    private:
        size_t _size;
        unsigned char *_array;
        int to_10;
        
};
```

### Eleven.cpp
```
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
```


### tests.cpp
```
#include <gtest/gtest.h>
#include "Eleven.h"

TEST(test_1, AllMetods)
{
	Eleven a("123");
    Eleven b("2");

	size_t sizea = a.get_size();
	size_t expectSizea = 3;
    size_t sizeb = b.get_size();
	size_t expectSizeb = 1;

	unsigned char* numsa = a.get_array();
	unsigned char expectNumsa[] = {'3', '2', '1'};
    unsigned char* numsb = b.get_array();
	unsigned char expectNumsb[] = {'2'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 386;
    int to_10b = b.translate_to_10();
    int expectto_10b = 2;
    
    std::string ab = a.plus(b);
    std::string expectab = ("323");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("31A");

    std::string aab = a.bigger(b);
    std::string expectaab = ("true");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equall(b);
    std::string expectaabb = ("false");

    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}
```
