#include <iostream>
#include "../headers/dmm.hpp"

int main() {

    double* d_ptr;
    d_ptr = New(3.14);
    Delete(d_ptr);
    d_ptr == nullptr;

    size_t s = 4;

    int* i_ptr = New_array<int>(s);

    std::cout << "Enter 4 integer elements for array: ";
    for (size_t i = 0; i < s; ++i) {
        std::cin >> i_ptr[i];
    }

    std::cout << "Inputed dynamic array: ";
    array_print(i_ptr, s);

    Delete_array(i_ptr, s);
    i_ptr == nullptr;

    return 0;
}