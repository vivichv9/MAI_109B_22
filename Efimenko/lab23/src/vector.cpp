#include "../include/vector.hpp"

template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 1;
    T* newArray = new T(1);
    array = newArray;
}

template <typename T>
Vector<T>::Vector(size_t capacity) {
    size = 0;
    this->capacity = capacity;
    T* newArray = new T(capacity);
    array = newArray;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] array;
}

template <typename T>
size_t Vector<T>::getCapacity() {
    return capacity;
}

template <typename T>
size_t Vector<T>::getSize() {
    return size;
}

template <typename T>
T* Vector<T>::front() {
    return size > 0 ? &array[0] : nullptr;
}

template <typename T>
T* Vector<T>::back() {
    return size > 0 ? &array[size-1] : nullptr;
}

template <typename T>
void Vector<T>::reserve(size_t n) {
    if (n < capacity) return;

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
    if (n > capacity) reserve(n);

    for (size_t i = size; i < n; ++i) {
        new (array + i) T(value);
    }

    if (n < size) {
        size = n;
    }
}

template <typename T>
void Vector<T>::pushBack(const T& data) {
    if (capacity == size) reserve(2 * size);
    
    new (array + size) T(data);
    ++size;
}

template <typename T>
void Vector<T>::popBack() {
    --size;
    array[size].~T();
}

template <typename T>
void Vector<T>::pop(size_t index) {
    //TODO
}

template <typename T>
void Vector<T>::push(size_t index, const T& data) {
    //TODO
}

template <typename T>
void Vector<T>::clear() {
    delete[] reinterpret_cast<int8_t*>(array); 
}

template <typename T>
void Vector<T>::shrinkToFit() {
    //TODO
}

template <typename T>
bool Vector<T>::empty() {
    return size == 0;
}

template<typename T>
T Vector<T>::at(size_t index) {
    return array[index];
}
