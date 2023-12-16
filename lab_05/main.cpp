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


int main(){

    auto begin = std::chrono::high_resolution_clock::now();

    std::map<int, int> map;
    for (size_t i = 0; i < 100000; i++){
        map.emplace(i, i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test_1 (без аллокатора): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";

    begin = std::chrono::high_resolution_clock::now();

    std::map<int, int, std::less<int>,Allocator<std::pair<const int,int>, 100000>> map_alloc;
    for (size_t i = 0; i < 100000; i++){
        map_alloc.emplace(i, i);
    }

    end = std::chrono::high_resolution_clock::now();
    std::cout << "test_2 (с аллокатором): " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";

    std::cout << "\n";

    std::cout << "std::map2" << "\n";
    std::map<int, int> map2;
    for (size_t i = 0; i < 10; i++){
        int res = factorial(i);
        map2.emplace(i, res);
    }
    for(const auto& [a,b]: map2){
        std::cout << a << " " << b << "\n";
    }
    std::cout << "\n";

    std::cout << "Двунаправленный список:" << "\n" << "\n";
    List<int, Allocator<int, 10>> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Первый элемент списка: " << *(list.begin()) << "\n";
    std::cout << "Количество элементов в списке: " << list.get_size() << "\n";
    std::cout << "Элементы списка: ";
    for (List<int, Allocator<int, 10>>::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n" << "\n";

    list.push_front(0);
    std::cout << "Первый элемент списка: " << *(list.begin()) << "\n";
    std::cout << "Количество элементов в списке: " << list.get_size() << "\n";
    std::cout << "Элементы списка: ";
    for (List<int, Allocator<int, 10>>::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n" << "\n";

    list.pop_back();
    list.pop_front();
    std::cout << "Первый элемент списка: " << *(list.begin()) << "\n";
    std::cout << "Количество элементов в списке: " << list.get_size() << "\n";
    std::cout << "Элементы списка: ";
    for (List<int, Allocator<int, 10>>::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n" << "\n";

    list.insert(1, 9);
    std::cout << "Первый элемент списка: " << *(list.begin()) << "\n";
    std::cout << "Количество элементов в списке: " << list.get_size() << "\n";
    std::cout << "Элементы списка: ";
    for (List<int, Allocator<int, 10>>::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n" << "\n";

    list.erase(2);
    std::cout << "Первый элемент списка: " << *(list.begin()) << "\n";
    std::cout << "Количество элементов в списке: " << list.get_size() << "\n";
    std::cout << "Элементы списка: ";
    for (List<int, Allocator<int, 10>>::Iterator it = list.begin(); it != list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n" << "\n";

    return 0;
}