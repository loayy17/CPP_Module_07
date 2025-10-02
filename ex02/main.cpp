#include <iostream>
#include "Array.hpp"

int main() {
    size_t len = 5;
    // Create an Arrays of different types
    Array<char>        charArray(5);
    Array<int>         intArray(len);
    Array<float>       floatArray(len);
    Array<std::string> strArray(len);
    Array<bool>        boolArray(len);
    // fill
    const size_t x = 5;
    for (size_t i = 0; i < charArray.size(); ++i) {
        charArray[i] = 'A' + i;
    }
    for (size_t i = 0; i < len; ++i) {
        intArray[i] = x;
    }

    for (size_t i = 0; i < len; ++i) {
        floatArray[i] = i * 1.5f;
    }

    for (size_t i = 0; i < len; ++i) {
        strArray[i] = std::string("String ") + std::string(1, 'A' + i);
    }

    for (size_t i = 0; i < len; ++i) {
        boolArray[i] = (i % 2 == 0);
    }

    // print
    std::cout << "Char Array: ";
    for (size_t i = 0; i < charArray.size(); ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Integer Array: ";
    for (size_t i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Float Array: ";
    for (size_t i = 0; i < floatArray.size(); ++i) {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "String Array: ";
    for (size_t i = 0; i < strArray.size(); ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Bool Array: ";
    for (size_t i = 0; i < boolArray.size(); ++i) {
        std::cout << std::boolalpha << boolArray[i] << " ";
    }
    std::cout << std::endl;

    // Copy constructor deep copy
    Array<int> copyIntArray = intArray;
    std::cout << "Copied Integer Array: ";
    for (size_t i = 0; i < copyIntArray.size(); ++i) {
        std::cout << copyIntArray[i] << " ";
    }
    std::cout << std::endl;

    // Assignment operator
    Array<float> assignFloatArray;
    assignFloatArray = floatArray;
    std::cout << "Assigned Float Array: ";
    for (size_t i = 0; i < assignFloatArray.size(); ++i) {
        std::cout << assignFloatArray[i] << " ";
    }
    std::cout << std::endl;

    // Exception handling
    try {
        std::cout << intArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        std::cout << strArray[-5] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Array<double> emptyArray;
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Array<int> zeroArray(0);
        std::cout << "Zero Array created successfully." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    // const Array
    const Array<int> constIntArray = intArray;
    std::cout << "Const Integer Array: ";
    for (size_t i = 0; i < constIntArray.size(); ++i) {
        std::cout << constIntArray[i] << " ";
    }
    return 0;
}