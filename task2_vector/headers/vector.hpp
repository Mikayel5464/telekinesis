#ifndef __VECTOR__H__
#define __VECTOR__H__

template <typename T>
class Vector {
    private:
        size_t m_size;
        size_t m_cap;
        T* m_arr;
        void recap(size_t); 

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
        T& at(size_t);
        bool empty();
        T& front();
        T& back();
        size_t size();
        size_t capacity();
        void print();
};

#include "../src/vector.cpp"

#endif