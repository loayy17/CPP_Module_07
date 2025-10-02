#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <string>
template <typename X>
void swap(X& x1, X& x2) {
    X temp = x1;
    x1     = x2;
    x2     = temp;
}

template <typename Y>
Y min(Y y1, Y y2) {
    return y1 < y2 ? y1 : y2;
}
template <typename Z>
Z max(Z z1, Z z2) {
    return z1 > z2 ? z1 : z2;
}

#endif