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