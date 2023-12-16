# Лабораторная 5
# Кайдалова Александра, М8О-212Б-22, Вариант 10
## Тема: Итераторы и аллокаторы
### Цель: 
1. Изучение устройства коллекций в стандартной библиотеке;
2. Получение навыков в использовании концепции «итератор»;
3. Получение навыков в использовании концепции «аллокатор».
#### Требования к программе:
1. Аллокатор
a. Реализовать свой аллокатор памяти. Проверить что он корректно работает для
контейнера std::map.
b. Аллокатор должен параметризоваться количеством выделяемых за раз элементов.
c. Освобождение конкретного элемента не предполагается - аллокатор должен
освобождать всю память самостоятельно.
2. Контейнер
a. Реализовать свой контейнер (согласно варианта задания), который по аналогии с
контейнерами stl, параметрезуя аллокатором.
3. Итератор
a. Реализовать итераторы (обычный и const)
b. Итератор должен соответствовать std::forward_iterator_tag

Прикладной код должен содержать следующие вызовы:
1. создание экземпляра std::map с созданным аллокатором;
2. заполнение 10 элементами, где ключ — это число от 0 до 9, а значение - факториал ключа;
3. вывод на экран всех значений (ключ и значение разделены пробелом) хранящихся в контейнере;
4. создание экземпляра своего контейнера для хранения int с собственным vаллокатором – заполнение контейнера и печать его элементов.

Вариант 9:
Двунаправленный список.
std::deque

#### main.cpp
```cpp
#include <iostream>
#include <map>
#include <chrono>
#include "allocator.h"
#include "list.h"

// Функция вычисления факториала
int factorial(int i){
    if (i <= 1){
        return 1;
    }
    return i * factorial(i - 1);
}

// Без аллокатора
void test_1(){
    auto begin = std::chrono::high_resolution_clock::now();

    std::map<int, int> map;
    for (size_t i = 0; i < 100000; i++){
        map.emplace(i, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test_1 (без аллокатора): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";
}

// С аллокатором
void test_2(){
    auto begin = std::chrono::high_resolution_clock::now();

    std::map<int, int, std::less<int>,Allocator<std::pair<const int,int>, 100000>> map;
    for (size_t i = 0; i < 100000; i++){
        map.emplace(i, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test_2 (с аллокатором): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";
}

// Функция печати информации о списке
void print(const List<int, Allocator<int, 10>>& myList){
    List<int, Allocator<int, 10>> list = myList;
    std::cout << "Первый элемент списка: " << *(list.begin()) << "\n";
    std::cout << "Количество элементов в списке: " << list.get_size() << "\n";
    std::cout << "Элементы списка: ";
    for (List<int, Allocator<int, 10>>::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n" << "\n";
}


int main(){

// Тесты
    test_1();
    test_2();
    std::cout << "\n";

// std::map
    std::cout << "std::map" << "\n";
    std::map<int, int> map;
    for (size_t i = 0; i < 10; i++){
        int res = factorial(i);
        map.emplace(i, res);
    }
    for(const auto& [a,b]: map){
        std::cout << a << " " << b << "\n";
    }
    std::cout << "\n";

// Двунаправленный список
    std::cout << "Двунаправленный список:" << "\n" << "\n";
    List<int, Allocator<int, 10>> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    print(list);

    list.push_front(0);
    print(list);

    list.pop_back();
    list.pop_front();
    print(list);

    list.insert(1, 9);
    print(list);

    list.erase(2);
    print(list);

    return 0;
}
```
#### allocator.h
```cpp
#pragma once
#include <iostream>
#include <deque>

template <class T, size_t SIZE>
class Allocator{

private:
    std::deque<T> used;
    std::deque<T*> free;
    size_t free_count;

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Allocator(){
        used.resize(SIZE);
        free.resize(SIZE);
        free_count = SIZE;

        for (size_t i = 0; i < free_count; ++i){
            free[i] = &used[i];
        }
    }

    ~Allocator(){
        for (size_t i = 0; i < free_count; ++i){
            free[i] = nullptr;
        }
    }

    template <class U>
    struct rebind{
        using other = Allocator<U, SIZE>;
    };

    T* allocate(size_t n){
        T* result = nullptr;

        if (free_count > 0) {
            result = free[free_count - 1];
            --free_count;
        } else {
            std::cout << "Память аллокатора переполнена." << "\n";
        }

        return result;
    }

    void deallocate(T* p, size_t n){
        free[free_count + 1] = p;
        ++free_count;
    }

    template<class U, class... Args>
    void construct(U* p, Args&&... args){
        new(p) U(std::forward<Args>(args)...);
    }

    void destroy(T* p){
        p->~T();
    }
};
```
#### list.h
```cpp
#include <iostream>
#include <memory>

template <typename T, typename Alloc = std::allocator<T>>
class List{

private:

// Узел списка
    struct Node{
        T data;
        Node* next;
        Node* prev;
    };

    using Alloc_traits = std::allocator_traits<Alloc>;
    using Alloc_Node = typename Alloc_traits::rebind_alloc<Node>;
    using Alloc_Node_traits = std::allocator_traits<Alloc_Node>;
    Node* head;
    Node* tail;
    size_t size;
    Alloc_Node alloc;

public:

// Обычный итератор
    class Iterator{

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node){
            current = node;
        }

        Iterator& operator++(){
            current = current->next;
            return *this;
        }

        T& operator*() const{
            return current->data;
        }

        bool operator==(const Iterator& other) const{
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const{
            return !(*this == other);
        }

    private:
        Node* current;
    };

// Константный итератор
    class ConstIterator{

    public:
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        ConstIterator(Node* node){
            current = node;
        }

        ConstIterator& operator++(){
            current = current->next;
            return *this;
        }

        reference operator*() const{
            return current->data;
        }

        bool operator==(const ConstIterator& other) const{
            return current == other.current;
        }

        bool operator!=(const ConstIterator& other) const{
            return !(*this == other);
        }

    private:
        Node* current;
    };
    
// Конструктор и деструктор списка
    List(): alloc(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~List(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            Alloc_Node_traits::destroy(alloc, temp);
            Alloc_Node_traits::deallocate(alloc, temp, 1);
        }
    }

// Методы списка
    int get_size() const{
        return size;
    }

    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(nullptr);
    }

    ConstIterator cbegin() const{
        return ConstIterator(head);
    }

    ConstIterator cend() const{
        return ConstIterator(nullptr);
    }

    void push_back(const T& value){
        Node* new_node = Alloc_Node_traits::allocate(alloc, 1);
        Alloc_Node_traits::construct(alloc, new_node, value);

        if (head == nullptr){
            head = tail = new_node;
        } 
        else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ++size;
    }
    
    void push_front(const T& value){
        Node* new_node = Alloc_Node_traits::allocate(alloc, 1);
        Alloc_Node_traits::construct(alloc, new_node, value);

        if (head == nullptr){
            head = tail = new_node;
        } 
        else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        ++size;
    }

    void pop_back(){
        if (tail == nullptr){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr){
            tail->next = nullptr;
        } 
        else{
            head = nullptr;
        }
        Alloc_Node_traits::destroy(alloc, temp);
        Alloc_Node_traits::deallocate(alloc, temp, 1);
        size--;
    }

    void pop_front(){
        if (head == nullptr){
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr){
            head->prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        Alloc_Node_traits::destroy(alloc, temp);
        Alloc_Node_traits::deallocate(alloc, temp, 1);
        size--;
    }

    void insert(size_t index, const T& value){
        if(index > size){
            std::cout << "Невозможно вставить эллемент " << value << ", так как в списке нет индекса: " << index << "\n";
        }
        if(index == 0){
            push_front(value);
        }
        else if(index == size){
            push_back(value);
        }
        else{
            Node* current = head;
            for(size_t i = 0; i < index; i++){
                current = current->next;
            }

            Node* new_node = Alloc_Node_traits::allocate(alloc, 1);
            Alloc_Node_traits::construct(alloc, new_node, value);

            new_node->prev = current->prev;
            new_node->next = current;
            current->prev->next = new_node;
            current->prev = new_node;

            size++;
        }
    }

    void erase(size_t index){
        if(index >= size){
            std::cout << "Нет данных с таким индексом." << "\n";
        }
        if(index == 0){
            pop_front();
        }
        else if(index == size - 1){
            pop_back();
        }
        else {
            Node* current = head;
            for(size_t i = 0; i < index; i++){
                current = current->next;
            }
            Node* delete_node = current;

            current->prev->next = current->next;
            current->next->prev = current->prev;
            
            Alloc_Node_traits::destroy(alloc, delete_node);
            Alloc_Node_traits::deallocate(alloc, delete_node, 1);
            
            size--;
        }
    }
};
```