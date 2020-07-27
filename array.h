//
//  array.h
//  cpplib
//
//  Created by Niklas Tom Hucke on 27.07.2020.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

// This contains a fixed size array type
#include <initializer_list>

namespace nitohu {

template<typename T, size_t S>
class Array {
public:
    Array() {}
    Array(std::initializer_list<T> l) {
        int i = 0;
        for (auto &it : l) {
            this->arr[i] = it;
            i++;
        }
    }
    constexpr size_t get_length() const { return S; }

    constexpr const T* begin() const {
        return (const int*)this->arr;
    }
    constexpr const T* end() const {
        return (const int*)(this->arr + S);
    }

    bool contains(T t) {
        for (size_t i = 0; i < S; i++) {
            if (this->arr[i] == t) {
                return true;
            }
        }
        return false;
    }

    T& operator[](size_t i) {
        return this->arr[i];
    }
    T operator[](size_t i) const {
        return this->arr[i];
    }
private:
    T arr[S];
};

}