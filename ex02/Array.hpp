#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <cstddef>
template <typename Arr>
class Array {
   public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    Arr&   operator[](size_t indexArray);
    const Arr& operator[](size_t indexArray) const;
    size_t size() const;
    ~Array();

   private:
    Arr*   _arr;
    size_t _len;
};
#include "Array.tpp"
#endif