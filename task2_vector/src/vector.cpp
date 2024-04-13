#ifndef VECTOR__CPP__
#define VECTOR__CPP__

#include <stdexcept>
#include "../headers/vector.hpp"

template <typename T>
Vector<T>::Vector(): m_size(1), m_cap(5), m_arr(new T[m_cap]) {}

template <typename T>
Vector<T>::Vector(type_of_size size)
    : m_size(size)
    , m_cap(m_size * 2)
    , m_arr(new val_type[m_cap])
{}

template <typename T>
Vector<T>::Vector(type_of_size size, const val_type& val) {
    this->m_size = size;
    this->m_cap = m_size * 2;
    this->m_arr = new val_type[m_cap];

    for (size_t i = 0; i < m_size; ++i) {
        this->m_arr[i] = val;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& rhv) {
    this->m_size = rhv.m_size;
    this->m_cap = rhv.m_cap;
    this->m_arr = new val_type[rhv.m_cap];

    for (size_t i = 0; i < m_size; ++i) {
        this->m_arr[i] = rhv.m_arr[i];
    }
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector& rhv) {
    if (this != &rhv) {
        clear();
        this->m_size = rhv.m_size;
        this->m_cap = rhv.m_cap;
        this->m_arr = new val_type[rhv.m_cap];

        for (size_t i = 0; i < m_size; ++i) {
            this->m_arr[i] = rhv.m_arr[i];
        }
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    clear();
}

template <typename T>
void Vector<T>::recap(type_of_size new_cap) {
    if (new_cap > m_cap) {
        pointer new_arr = new val_type[new_cap];

        for (type_of_size i = 0; i < m_size; ++i) {
            new_arr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = new_arr;
        m_cap = new_cap;
    }
}

template <typename T>
void Vector<T>::init(type_of_size size) {
    m_arr = new val_type[size];
    m_size = size;
    m_cap = size;
}

template <typename T>
void Vector<T>::init(type_of_size size, const_referance val) {
    init(size);

    for (type_of_size i = 0; i < size; ++i) {
        m_arr[i] = val;
    }
}

template <typename T>
void Vector<T>::clear() {
    delete[] m_arr;
    m_arr = nullptr;
    m_size = 0;
    m_cap = 0;
}

template <typename T>
void Vector<T>::resize(type_of_size size, const_referance val) {
    if (size < m_size) {
        m_size = size;
    }
    else if (size > m_size) {
        if (size > m_cap) {
            recap(size);
        }
        
        for (type_of_size i = m_size; i < m_size; ++i) {
                m_arr[i] = val;
        }

        m_size = size;
    }
}

template <typename T>
void Vector<T>::push_back(const_referance val) {
    if (m_size == m_cap) {
        recap(2 * m_size);
    }

    m_arr[m_size] = val;
    ++m_size;
}

template <typename T>
void Vector<T>::pop_back() {
    if (m_size > 0) {
        --m_size;
    }
}

template <typename T>
void Vector<T>::insert(type_of_size index, const_referance val) {
    if (index <= m_size) {
        if (m_size == m_cap) {
            recap(2 * m_size);
        }

        for (type_of_size i = m_size; i > index; --i) {
            m_arr[i] = m_arr[i - 1];
        }

        m_arr[index] = val;
        ++m_size;
    }
}

template <typename T>
void Vector<T>::erase(type_of_size index) {
    if (index < m_size) {
        for (type_of_size i = index; i < m_size - 1; ++i) {
            m_arr[i] = m_arr[i + 1];
        }

        --m_size;
    }
}

template <typename T>
typename Vector<T>::referance
Vector<T>::at(type_of_size index) {
    if (index >= m_size) {
        throw std::out_of_range("Index is out of range!");
    }

    return m_arr[index];
}

template <typename T>
bool Vector<T>::empty() {
    if (m_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
typename Vector<T>::referance
Vector<T>::front() {
    return m_arr[0];
}

template <typename T>
typename Vector<T>::referance
Vector<T>::back() {
    return m_arr[m_size - 1];
}

template <typename T>
typename Vector<T>::type_of_size
Vector<T>::size() {
    return m_size;
}

template <typename T>
typename Vector<T>::type_of_size
Vector<T>::capacity() {
    return m_cap;
}

template <typename T>
void Vector<T>::print() {
    for (size_t i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
}

#endif