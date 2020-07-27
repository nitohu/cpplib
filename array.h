//
//  array.h
//  cpplib
//
//  Created by Niklas Tom Hucke on 27.07.2020.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

// This contains a fixed size array type
namespace nitohu {

template<typename T, size_t S>
class Array {
public:
    constexpr size_t get_length() const { return S; }

    T& operator[](size_t i) {
        return this->arr[i];
    }
private:
    T arr[S];
};

}