#include "../headers/dmm.hpp"
#include <iostream>

void* operator_new(size_t size) {
    void* ptr = std::malloc(size);

    if (!ptr) {
        throw std::bad_alloc();
    }

    return ptr;
}

void operator_delete(void* ptr) {
    if (ptr) {
        std::free(ptr);
    }

    return;
}

template <typename T>
void array_print(T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

template <typename T>
T* New(T num) {
    void* p = ::operator_new(sizeof(T));
    T* ptr = static_cast<T*>(p);
    *ptr = num;

    new (ptr) T;

    return ptr;
}

template <typename T>
void Delete(T* ptr) {
    if (ptr) {
        ::operator_delete(ptr);

        T::~T(ptr);
    }
}

template <typename T>
T* New_array(size_t size) {
    void* p = ::operator_new(size * sizeof(T));
    T* ptr = static_cast<T*>(p);

    for (size_t i = 0; i < size; ++i) {
        new (ptr + i) T;
    }

    return ptr;
}

template <typename T>
void Delete_array(T* ptr, size_t size) {
    if (ptr) {
        for (size_t i = size - 1; i != -1; --i) {
            T::~T(ptr + i);
        }
        ::operator_delete(ptr);
    }
}
