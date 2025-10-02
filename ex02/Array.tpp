
#include "Array.hpp"
template <typename Arr>
Array<Arr>::Array() : _arr(0), _len(0) {}

template <typename Arr>
Array<Arr>::Array(unsigned int n) : _arr(0), _len(0) {
    _len = static_cast<size_t>(n);
    if (n == 0) {
        _arr = 0;
    } else {
        _arr = new Arr[_len]();
    }
}

template <typename Arr>
Array<Arr>::Array(const Array<Arr>& other) : _arr(0), _len(other._len) {
    if (_len > 0) {
        _arr = new Arr[_len];
        for (size_t i = 0; i < _len; i++) {
            _arr[i] = other._arr[i];
        }
    } else {
        _arr = 0;
        _len = 0;
    }
}

template <typename Arr>
Array<Arr>& Array<Arr>::operator=(const Array<Arr>& other) {
    if (this == &other)
        return *this;

    delete[] _arr;
    _len = other._len;
    if (_len > 0) {
        _arr = new Arr[_len];
        for (size_t i = 0; i < _len; i++) {
            _arr[i] = other._arr[i];
        }
    } else {
        _arr = 0;
    }
    return *this;
}

template <typename Arr>
Arr& Array<Arr>::operator[](size_t indexArray) {
    if (indexArray >= _len) {
        throw std::out_of_range("Index out of bounds");
    }
    return _arr[indexArray];
}

template <typename Arr>
const Arr& Array<Arr>::operator[](size_t indexArray) const {
    if (indexArray >= _len) {
        throw std::out_of_range("Index out of bounds");
    }
    return _arr[indexArray];
}

template <typename Arr>
size_t Array<Arr>::size() const {
    return _len;
}

template <typename Arr>
Array<Arr>::~Array() {
    delete[] _arr;
}
