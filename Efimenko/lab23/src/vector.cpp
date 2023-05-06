#include <algorithm>
#include "../include/vector.hpp"

template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 1;
    array = new T[1];
}

template <typename T>
Vector<T>::Vector(size_t capacity) {
    size = 0;
    this->capacity = capacity;
    array = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector(vec.capacity) {
    memcpy(array, vec.array, capacity * sizeof(T));
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst) {
    size = lst.size;
    capacity = size;
    array = new T[size];
    std::copy(lst.begin(), lst.end(), array);
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector vec) {
    swap(vec);
    return *this;
}

template <typename T>
void Vector<T>::swap(Vector& vec) {
    std::swap(capacity, vec.capacity);
    std::swap(size, vec.size);
    std::swap(array, vec.array);
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return array[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return array[index];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] reinterpret_cast<int8_t*>(array);
}

template <typename T>
size_t Vector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
size_t Vector<T>::get_size() const {
    return size;
}

template <typename T>
const T& Vector<T>::front() const {
    return size > 0 ? array[0] : nullptr;
}

template <typename T>
T& Vector<T>::front() {
    return size > 0 ? array[0] : nullptr;
}

template <typename T>
const T& Vector<T>::back() const {
    return size > 0 ? array[size - 1] : nullptr;
}

template <typename T>
T& Vector<T>::back() {
    return size > 0 ? array[size - 1] : nullptr;
}

template <typename T>
void Vector<T>::reserve(size_t n) {
    if (n < capacity) {
        return;
    }

    T* newArr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);

    try {
        std::uninitialized_copy(array, array + size, newArr);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(newArr);
        throw;
    }

    for (size_t i = 0; i < size; ++i) {
        array[i].~T();
    }

    delete[] reinterpret_cast<int8_t*>(array);
    array = newArr;
    capacity = n;    
}

template <typename T>
void Vector<T>::resize(size_t n, const T& value) {
    if (n > capacity) {
        reserve(n);
    } 

    for (size_t i = size; i < n; ++i) {
        new (array + i) T(value);
    }

    if (n < size) {
        size = n;
    }
}

template <typename T>
void Vector<T>::push_back(const T& data) {
    if (capacity == size) {
        reserve(2 * size);
    }
    new (array + size) T(data);
    ++size;
}

template <typename T>
void Vector<T>::pop_back() {
    --size;
    array[size].~T();
}

template <typename T>
void Vector<T>::clear() {
    size_t sz_copy = size;

    for (size_t i = 0; i < sz_copy; ++i) {
        array[i].~T();
        size--;
    }
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    T* newArr = reinterpret_cast<T*>(new int8_t[size * sizeof(T)]);

    try {
        std::uninitialized_copy(array, array + size, newArr);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(newArr);
        throw;
    }

    for (size_t i = 0; i < size; ++i) {
        array[i].~T();
    }

    delete[] reinterpret_cast<int8_t*>(array);
    array = newArr;
    capacity = size;

}

template <typename T>
bool Vector<T>::empty() const {
    return size;
}
