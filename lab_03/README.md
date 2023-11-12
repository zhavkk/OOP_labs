# Лабораторная работа 3. Классы
## Автор: Жаворонков М.Н, группа М8О-212Б-22, вариант 9

Разработать программу на языке C++ согласно варианту задания. Программа на C++ должна собираться с помощью системы сборки CMake. Программа должна получать данные из стандартного ввода (std::cin) и выводить данные в стандартный вывод (std::cout).
Необходимо зарегистрироваться на GitHub и создать репозитарий для задания лабораторных работ.
Преподавателю необходимо предъявить ссылку на публичный репозиторий на Github. Необходимо реализовать функцию согласно варианту задания. Функция должна быть помещена в отдельный файл.

Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения.
Все классы должны поддерживать набор общих методов:
1. Вычисление геометрического центра фигуры вращения;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры через перегрузку оператора << для std::ostream;
3. Чтение из стандартного потока данных фигур через перегрузку оператора >> для std::istream
4. Вычисление площади фигуры через перегрузку оператора приведения к типу double;

Создать программу, которая позволяет:
- Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
- Сохранять созданные фигуры в динамический массив (по аналогии с предыдущей лабораторной работой Array) указатели на фигуру (Figure*)
- Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и сравнения (==)
- Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр и площадь.
- Необходимо уметь вычислять общую площадь фигур в массиве. •Удалять из массива фигуру по индексу;
  Фигуры : треугольник, квадрат, прямоугольник
## Программы 

### main.cpp
```
#include <iostream>
#include "array.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include <cmath>

int main() {
    std::vector<double> tria_x{0.0, 10.0, 0.0};
    std::vector<double> tria_y{0.0, 0.0, 10.0};

    std::vector<double> rect_x{2, 1, 3, 4};
    std::vector<double> rect_y{0, 1, 2, 3};

    std::vector<double> sq_x{1, 2, 3, 4};
    std::vector<double> sq_y{0, 1, 2, 3};

    Triangle p = Triangle(tria_x, tria_y);
    Rectangle h = Rectangle(rect_x, rect_y);
    Square l = Square(sq_x, sq_y);

    Array q = Array(3);
    q.changefigures(0, new Triangle(tria_x, tria_y));
    q.changefigures(1, new Rectangle(rect_x, rect_y));
    q.changefigures(2, new Square(sq_x, sq_y));

    for (int i = 0; i < 3; ++i) {
        const Figure* fig = q[i];
        if (q[i] == nullptr) {
            std::cout << "The figure has been deleted" << std::endl;
        } else {
            std::cout << "Figure " << i + 1 << ":\n";
            std::cout << "Ploshad: " << fig->ploshad() << std::endl;
            std::pair<double, double> center = fig->center();
            std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        }
    }

    std::cout << std::endl;

    Triangle ex = Triangle();
    ex = p;
    std::cout << "Ploshad of ex: " << ex.ploshad() << std::endl;
    std::pair<double, double> ex_center = ex.center();
    std::cout << "Center of ex: (" << ex_center.first << ", " << ex_center.second << ")\n";

    return 0;
}

```

### figure.h
```

#pragma once
#include <string>
#include <iostream>
#include <utility>
class Figure{
    protected:
        Figure()=default;

    public:
        virtual ~Figure()=default;
        virtual std::pair<double,double> center() const = 0;
        virtual double ploshad() const = 0;
        virtual explicit operator double() const = 0;
                
};
```

### array.h
```
#include "figure.h"

class Array{


    public:
        Array();
        Array(size_t size);

        ~Array();
            
        void del_figure(size_t index);
        double avg_ploshad(); //srednya ploshad
        
        Figure *operator[](size_t index);

        void changefigures(size_t index, Figure *other);
        size_t get_size(){
            return _size;
        }
        

    private:
        size_t _size;
        Figure** _figures;


};
```


### array.cpp
```
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
```
### triangle.h
```
#pragma once

#include <iostream>
#include "figure.h"
#include <utility>
#include <vector>
class Triangle : public Figure{


    
    public:
        Triangle();
        Triangle(std::vector<double> &x,std::vector<double> &y);
        ~Triangle();

        bool operator==(Triangle &other) const;
        Triangle &operator=(Triangle &other);
        Triangle &operator=(Triangle &&other);

        
        friend std::ostream &operator<<(std::ostream& os,const Triangle& p);
        friend std::istream &operator>>(std::istream& is,Triangle& p);


        double ploshad() const override{
            return surface;
        }

        std::pair<double,double> center() const override{
            return std::make_pair(mid_x, mid_y);  
        }

        operator double() const override{
            return surface;
        }


    protected:

        std::vector<double> x_kords;
        std::vector<double> y_kords;
        double mid_x;
        double mid_y;
        double surface;




};
inline std::ostream& operator<<(std::ostream& os, const Triangle& p) {
    for (int i = 0; i < 3; ++i) {
        os << "Koords  " << i + 1 << ": ( " << p.x_kords[i] << " , " << p.y_kords[i] << ")\n";
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Triangle& p) {
    std::vector<double> x_k(3), y_k(3);
    for (int i = 0; i < 3; ++i) {
        std::cout << "Vvedite koords " << i + 1 << ":\n";
        double x, y;
        std::cout << "x: ";
        is >> x;
        std::cout << "y: ";
        is >> y;
        x_k[i] = x;
        y_k[i] = y;
    }
    p = Triangle(x_k, y_k);
    return is;
}
```
### triangle.cpp
```
#include "triangle.h"
#include <exception>
#include <cmath>
Triangle::Triangle(){
    x_kords={0,0,0};
    y_kords={0,0,0};
    mid_x=0.0;
    mid_y=0.0;
    surface=0;

}



Triangle::Triangle(std::vector<double> &x,std::vector<double> &y){
    mid_x=0.0;
    mid_y=0.0;
    // if (x.size() != 3 || y.size() != 3) {
    //     x_kords.resize(3);
    //     y_kords.resize(3);
    //     throw std::invalid_argument("koords are wrong");

    // }
    if(x_kords.size()!=3){
        x_kords.resize(3);
    }
    if(y_kords.size()!=3){
        y_kords.resize(3);
    }
    for (int i = 0; i < 3; ++i)
    {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    mid_x=mid_x/3;
    mid_y=mid_y/3;
    double a = std::sqrt(std::pow((x[1] - x[0]),2) + std::pow((y[1] - y[0]),2));
    double b = std::sqrt(std::pow((x[2] - x[1]),2) + std::pow((y[2] - y[1]),2));
    double c = std::sqrt(std::pow((x[2] - x[0]),2) + std::pow((y[2] - y[0]),2));

    double p = (a + b + c) / 2;
    surface = std::sqrt(p * (p - a) * (p - b) * (p - c));
    
}

Triangle::~Triangle(){
    x_kords={};
    y_kords={};
    mid_x=0;
    mid_y=0;
    surface=0;
}
bool Triangle::operator==(Triangle &other) const {
    if(surface==other.surface){
        return true;
    }
    else{
        return false;
    }

}

Triangle &Triangle::operator=(Triangle &other){
    x_kords=other.x_kords;
    y_kords=other.y_kords;
    mid_x=other.mid_x;
    mid_y=other.mid_y;
    surface=other.surface;
    return *this;
}
Triangle &Triangle::operator=(Triangle &&other){
    x_kords=std::move(other.x_kords);
    y_kords=std::move(other.y_kords);
    mid_x=std::move(other.mid_x);
    mid_y=std::move(other.mid_y);
    surface=std::move(other.surface);
    return *this;
}
```
### rectangle.h
```
#pragma once
#include <iostream>
#include "figure.h"
#include <utility>
#include <vector>
class Rectangle : public Figure{

    public:
        Rectangle();
        Rectangle(std::vector<double> &x,std::vector<double> &y);
        ~Rectangle();
        bool operator==(Rectangle &other) const;
        Rectangle &operator=(Rectangle &other);
        Rectangle &operator=(Rectangle &&other);
        
        std::pair<double,double> center() const override{
            return std::make_pair(mid_x,mid_y);
        }
        friend std::ostream &operator<<(std::ostream &os,const Rectangle &p);
        friend std::istream &operator>>(std::istream &is,Rectangle &p);
        double ploshad() const override{
            return surface;
        }
        operator double() const override{
            return surface;
        }

    
    protected:
        double mid_x;
        double mid_y;
        double surface;
        std::vector<double> x_kords;
        std::vector<double> y_kords;

};

inline std::ostream &operator<<(std::ostream &os,const Rectangle &p){
    for(size_t i{0};i<4;++i){
        os<<"Koords : "<<i+1<<"( "<<p.x_kords[i]<<","<<p.y_kords[i]<<")\n";
    }
    return os;
}
inline std::istream &operator>>(std::istream &is,Rectangle &p){
    double x,y;
    std::vector<double> x_k(4),y_k(4);
    for(size_t i{0};i<4;++i){
        std::cout<<"Vvedite kords "<<i+1<<":\n";
        std::cout<<"x : ";
        is>>x;
        std::cout<<"y : ";
        is>>y;
        x_k[i]=x;
        y_k[i]=y;

    }
    p=Rectangle(x_k,y_k);
    return is;
}
```
### rectangle.cpp
```
#include "rectangle.h"
#include <exception>
#include <cmath>

Rectangle::Rectangle(){
    x_kords={0.0,0.0,0.0,0.0};
    y_kords={0.0,0.0,0.0,0.0};
    mid_x=0.0;
    mid_y=0.0;
    surface=0;

}

Rectangle::Rectangle(std::vector<double> &x,std::vector<double> &y){
    mid_x=0;
    mid_y=0;
    if(x_kords.size()!=4){
        x_kords.resize(4);
    }
    if(y_kords.size()!=4){
        y_kords.resize(4);
    }
    for (int i = 0; i < 4; ++i)
    {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    double xA = x_kords[0];
    double yA = y_kords[0];
    double xB = x_kords[1];
    double yB = y_kords[1];
    double xC = x_kords[2];
    double yC = y_kords[2];
    double xD = x_kords[3];
    double yD = y_kords[3];

    double length = std::abs(std::sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA)));
    double width = std::abs(std::sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB)));
    mid_x = (xA + xC) / 2;
    mid_y = (yA + yC) / 2;

    surface=length*width;
    

}

Rectangle::~Rectangle(){
    x_kords={};
    y_kords={};
    mid_x=0;
    mid_y=0;
    surface=0;
}

bool Rectangle::operator==(Rectangle &other) const {
    if(surface==other.surface){
        return true;
    }
    else{
        return false;

    }
}
Rectangle &Rectangle::operator=(Rectangle &other){
    x_kords=other.x_kords;
    y_kords=other.y_kords;
    mid_x=other.mid_x;
    mid_y=other.mid_y;
    surface=other.surface;
    return *this;
}
Rectangle &Rectangle::operator=(Rectangle &&other){
    x_kords=std::move(other.x_kords);
    y_kords=std::move(other.y_kords);
    mid_x=std::move(other.mid_x);
    mid_y=std::move(other.mid_y);
    surface=std::move(other.surface);
    return *this;

}
```
### square.h
```
#pragma once
#include <iostream>
#include "figure.h"
#include <utility>
#include <vector>

class Square : public Figure{



    public:
        Square();
        Square(std::vector<double> &x,std::vector<double> &y);
        ~Square();
        bool operator==(Square &other) const;
        Square &operator=(Square &other);
        Square &operator=(Square &&other);
        friend std::ostream &operator<<(std::ostream& os, const Square&);
        friend std::istream &operator>>(std::istream& is, Square&);

        double ploshad() const override{
            return surface;
        }
        std::pair<double,double> center() const override{

            return std::make_pair(mid_x,mid_y);
        }
        operator double() const override{
            return surface;
        }



    protected:
        std::vector<double> x_kords;
        std::vector<double> y_kords;
        double surface;
        double mid_x;
        double mid_y;


};
inline std::ostream &operator<<(std::ostream& os, const Square& p){
    for(int i = 0; i<4;++i){
        os<<"Koords :"<<i+1<<"( : "<<p.x_kords[i]<<","<<p.y_kords[i]<<" )\n";

    }
    return os;

}

inline std::istream &operator>>(std::istream& is,Square&p){
    std::vector<double> x_k(4),y_k(4);
    double x,y;
    for(int i=0;i<4;++i){
        std::cout<<"Vvedite koords"<<i+1<<":\n";
        std::cout<<"x: ";
        is>>x;
        std::cout<<"y: ";
        is>>y;
        x_k[i]=x;
        y_k[i]=y;
    }
    p=Square(x_k,y_k);
    return is;
}
```
### square.cpp
```
#include "square.h"
#include <exception>
#include <cmath>
Square::Square(){
    x_kords={0.0,0.0,0.0,0.0};
    y_kords={0.0,0.0,0.0,0.0};
    mid_x=0.0;
    mid_y=0.0;
    surface=0;

}

Square::Square(std::vector<double> &x,std::vector<double> &y){
    mid_x=0.0;
    mid_y=0.0;
    if(x_kords.size()!=4){
        x_kords.resize(4);
    }
    if(y_kords.size()!=4){
        y_kords.resize(4);
    }

    for (int i = 0; i < 4; ++i)
    {
        x_kords[i] = x[i];
        y_kords[i] = y[i];
        mid_x += x[i];
        mid_y += y[i];
    }
    mid_x=mid_x/4;
    mid_y=mid_y/4;
    double x1 = x_kords[0];
    double y1 = y_kords[0];
    double x2 = x_kords[1];
    double y2 = y_kords[1];

    // Вычислите расстояние между вершинами A и B
    double side = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    surface=side*side;

}

Square::~Square(){
    x_kords={};
    y_kords={};
    mid_x=0;
    mid_y=0;
    surface=0;
}

bool Square::operator==(Square &other) const{
    if(surface==other.surface){
        return true;
    }
    else{
        return false;

    }
}
Square &Square::operator=(Square &other){
    x_kords=other.x_kords;
    y_kords=other.y_kords;
    mid_x=other.mid_x;
    mid_y=other.mid_y;
    surface=other.surface;
    return *this;
}
Square &Square::operator=(Square &&other){
    x_kords=std::move(other.x_kords);
    y_kords=std::move(other.y_kords);
    mid_x=std::move(other.mid_x);
    mid_y=std::move(other.mid_y);
    surface=std::move(other.surface);
    return *this;

}

```
### tests.cpp
```
#include <gtest/gtest.h>
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"

TEST(Triangle, EmptyConstructor) {
    Triangle t;
    EXPECT_DOUBLE_EQ(t.ploshad(), 0.0);
    EXPECT_EQ(t.center(), std::make_pair(0.0, 0.0));
}

TEST(Triangle, VectorConstructor) {
    std::vector<double> x = {0.0, 10.0, 0.0};
    std::vector<double> y = {0.0, 0.0, 10.0};
    Triangle t(x, y);
    EXPECT_DOUBLE_EQ(t.ploshad(), 50.0);
    EXPECT_NEAR(t.center().first, 3.33333, 0.00001);
    EXPECT_NEAR(t.center().second, 3.33333, 0.00001);
}


TEST(Triangle, AssignmentOperator) {
    std::vector<double> x1 = {0.0, 10.0, 0.0};
    std::vector<double> y1 = {0.0, 0.0, 10.0};
    Triangle t1(x1, y1);
    
    std::vector<double> x2 = {0.0, 5.0, 0.0};
    std::vector<double> y2 = {0.0, 0.0, 5.0};
    Triangle t2(x2, y2);

    t2 = t1;

    EXPECT_DOUBLE_EQ(t2.ploshad(), 50.0);
    EXPECT_NEAR(t2.center().first, 3.33333, 0.00001);
    EXPECT_NEAR(t2.center().second, 3.33333, 0.00001);
}

TEST(Square, EmptyConstructor) {
    Square s;
    EXPECT_DOUBLE_EQ(s.ploshad(), 0.0);
    EXPECT_EQ(s.center(), std::make_pair(0.0, 0.0));
}

TEST(Square, VectorConstructor) {
    std::vector<double> x = {0.0, 10.0, 10.0, 0.0};
    std::vector<double> y = {0.0, 0.0, 10.0, 10.0};
    Square s(x, y);
    EXPECT_DOUBLE_EQ(s.ploshad(), 100.0);
    EXPECT_EQ(s.center(), std::make_pair(5.0, 5.0));
}

TEST(Rectangle, EmptyConstructor) {
    Rectangle r;
    EXPECT_DOUBLE_EQ(r.ploshad(), 0.0);
    EXPECT_EQ(r.center(), std::make_pair(0.0, 0.0));
}

TEST(Rectangle, VectorConstructor) {
    std::vector<double> x = {0.0, 10.0, 10.0, 0.0};
    std::vector<double> y = {0.0, 0.0, 5.0, 5.0};
    Rectangle r(x, y);
    EXPECT_DOUBLE_EQ(r.ploshad(), 50.0);
    EXPECT_EQ(r.center(), std::make_pair(5.0, 2.5));
}

TEST(Array, EmptyConstructor) {
    Array a;
    EXPECT_EQ(a.get_size(), 10);
    for (size_t i = 0; i < a.get_size(); ++i) {
        EXPECT_EQ(a[i], nullptr);
    }
}

TEST(Array, SizeConstructor) {
    Array a(15);
    EXPECT_EQ(a.get_size(), 15);
    for (size_t i = 0; i < a.get_size(); ++i) {
        EXPECT_EQ(a[i], nullptr);
    }
}
```
