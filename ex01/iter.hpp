#ifndef ITER_HPP
#define ITER_HPP
#include <stddef.h>
#include <iostream>
template <typename Arr, typename Fnc>
void iter(Arr *ptrArr, const size_t len, Fnc fn) {
    for (size_t i = 0; i < len; i++) {
        fn(ptrArr[i]);
    }
};

#endif