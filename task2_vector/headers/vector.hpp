#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <iostream>

template <typename T>
class Vector {
    private:
        size_t m_size;
        size_t m_cap;
        T* m_arr;
        void recap(size_t);

    public:
        using val_type = T;
        using type_of_size = size_t;
        using referance = val_type&;
        using const_referance = const val_type&;
        using pointer = val_type*;
        using const_pointer = const pointer;

    public:
        Vector();
        Vector(size_t);
        Vector(size_t, const T&);
        Vector(const Vector&);
        const Vector& operator=(const Vector& rhv);
        ~Vector();
        
        void init(size_t);
        void init(size_t, const T&);
        void clear();
        void resize(size_t, const T&);
        void push_back(const T&);
        void pop_back();
        void insert(size_t, const T&);
        void erase(size_t);
        referance at(size_t);
        bool empty();
        referance front();
        referance back();
        type_of_size size();
        type_of_size capacity();
        void print();
};

#include "../src/vector.cpp"

#endif