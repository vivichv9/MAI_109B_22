#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>

template<typename T>
class Vector {
    private:
        size_t capacity = 0;
        size_t size = 0;
        T* array = nullptr;

        void swap(Vector&);

    public:
        Vector();   
        Vector(size_t);
        Vector(std::initializer_list<T>);
        Vector(const Vector&);
        Vector& operator=(Vector);
        ~Vector();

        size_t get_size() const;
        size_t get_capacity() const;

        bool empty() const;
        void resize(size_t, const T& = T());
        void push_back(const T&);
        void reserve(size_t n);
        void pop_back();
        void clear();
        void shrink_to_fit();

        T& operator[](size_t);
        T& front();
        T& back();
        const T& operator[](size_t) const;
        const T& back() const;
        const T& front() const;

};

#include "../src/vector.cpp"

#endif

