#include "iter.hpp"
#include <iostream>
#include <string>
void addTwo(int& a){
    a += 2;
}
void addTwo(std::string& a){
    a += "2";
}
void addTwo(float& a){
    a += 2.5f;
}

void addTwo(double& a){
    a += 2.5;
}

int main(){
    std::string str[] = {"1","2","3","4","5","6","7","8","9"};
    std::cout << "Before: " << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << str[i] << " ";
    }
    std::cout << "\nAfter: " << std::endl;
    ::iter(str, static_cast<size_t>(sizeof(str) / sizeof(str[0])), static_cast<void (*)(std::string &)>(addTwo));
    for (int i = 0; i < 9; i++) {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;

    
    int integers[] = {1,2,3,4,5,6,7,8,9};
    std::cout << "Before: " << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << integers[i] << " ";
    }
    ::iter(integers, static_cast<size_t>(sizeof(integers) / sizeof(integers[0])), static_cast<void (*)(int &)>(addTwo));
    std::cout << "\nAfter: " << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << integers[i] << " ";
    }
    std::cout << std::endl;

    float floaters[] = {1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f};
    std::cout << "Before: " << std::endl;
    for(int i = 0; i < 9; i++) {
        std::cout << floaters[i] << " ";
    }
    ::iter(floaters, static_cast<size_t>(sizeof(floaters) / sizeof(floaters[0])), static_cast<void (*)(float &)>(addTwo));
    std::cout << "\nAfter: " << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << floaters[i] << " ";
    }
    std::cout << std::endl;

    double doublers[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    ::iter(doublers, static_cast<size_t>(sizeof(doublers) / sizeof(doublers[0])), static_cast<void (*)(double &)>(addTwo));
    std::cout << "After: " << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << doublers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}