#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>

template<typename T>
class Vector {
    private:
        size_t capacity = 0;
        size_t size = 0;
        T* array = nullptr;

    public:
        Vector();   
        explicit Vector(size_t capacity);
        ~Vector();
        size_t getSize();
        size_t getCapacity();

        bool empty();

        void resize(size_t n, const T& value = T());
        void pop(size_t index);
        void pushBack(const T& data);
        void push(size_t index, const T& data);
        void reserve(size_t n);
        void popBack();
        void clear();
        void shrinkToFit();

        T at(size_t index);
        T* front();
        T* back();
};

#include "../src/vector.cpp"

#endif

