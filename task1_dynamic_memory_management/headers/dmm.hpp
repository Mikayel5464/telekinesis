#ifndef __DMM__HPP__
#define __DMM__HPP__
#include <iostream>

void* operator_new(size_t);
void operator_delete(void*);

template <typename T>
void array_print(T*, size_t);

// new for single variable
template <typename T>
T* New(T);

// delete for single variable
template <typename T>
void Delete(T*);

// new for array
template <typename T>
T* New_array(size_t);

// delete for array
template <typename T>
void Delete_array(T*, size_t);

#include "../src/dmm.cpp"

#endif