#include <iostream>
#include "../headers/vector.hpp"

int main() {
    Vector<int>vec1(10);
    Vector<int>vec2(10, 9);
    Vector<int>vec3(vec1);

    vec2.print();
    std::cout << std::endl;
    
    vec2.insert(3, 5);
    vec2.pop_back();
    vec2.print();
    std::cout << std::endl;
    
    vec2.erase(3);
    vec2.print();
    std::cout << std::endl;

    vec3.print();
    std::cout << std::endl;

    return 0;
}