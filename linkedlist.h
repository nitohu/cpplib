//
//  linkedlist.h
//  cpplib
//
//  Created by Niklas Tom Hucke on 24.07.2020.
//  Copyright © 2019 Niklas Tom Hucke. All rights reserved.
//

#include <stdexcept>
#include <initializer_list>
#include <string>
#include <iostream>


// This contains a dynamic "array" (with a LinkedList as a basis)
namespace nitohu {
template<typename T>
class LLElem  {
public:
    LLElem() {}
    LLElem(T x) {
        this->value = x;
    }

    LLElem<T>* operator++(int) {
        return this->next;
    }
    LLElem<T>* operator++() {
        return this->next;
    }

    LLElem<T>* operator--(int) {
        return this->prev;
    }
    LLElem<T>* operator--() {
        return this->prev;
    }

    T value;
    LLElem<T> *next = nullptr;
    LLElem<T> *prev = nullptr;
};

template<typename T>
class LinkedList {
public:
    LinkedList() {}
    LinkedList(std::initializer_list<T> l) {
        for (auto i = l.begin(); i != l.end(); i++) {
            this->append(*i);
        }
    }
    ~LinkedList() {
        while (this->tail->prev != nullptr) {
            this->tail = this->tail->prev;
            delete this->tail->next;
            this->tail->next = nullptr;
        }
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void prepend(int x) {
        LLElem<T> *e = new LLElem<T>(x);
        e->next = this->head;
        this->head->prev = e;
        this->head = e;
        this->size++;
    }
    void append(int x) {
        LLElem<T> *e = new LLElem<T>(x);
        if (this->head == nullptr) {
            this->size = 1;
            this->head = e;
            this->tail = e;
            return;
        }
        this->size++;
        this->tail->next = e;
        e->prev = this->tail;
        this->tail = e;
    }

    void pop() {
        if(this->head == nullptr) {
            throw "Array is empty.";
        } else if (this->tail->prev == nullptr) {
            this->head = nullptr;
            delete this->tail;
            this->tail = nullptr;
        } else if (this->tail->prev != nullptr) {
            this->tail = this->tail->prev;
            delete this->tail->next;
            this->tail->next = nullptr;
        }
        this->size--;
    }
    void cut(size_t x, size_t y) {
        if (x > this->get_length() || y > this->get_length()) {
            throw "x or y is out of range.";
        }
        if (this->get_length() < 2) {
            throw "Length must be bigger than 2.";
        }
        if (x > y) {
            throw "x must be smaller than y.";
        }
        LLElem<T> *e = this->head;
        for (size_t i = 0; i < y; i++) {
            if (i >= x) {
                LLElem<T> *prev = e->prev;
                LLElem<T> *next = e->next;
                if (prev == nullptr) {
                    this->head = next;
                } else {
                    prev->next = next;
                }
                if (next == nullptr) {
                    this->tail = prev;
                } else {
                    next->prev = prev;
                }
                delete e;
                e = (prev == nullptr) ? next : prev;
                this->size--;
            }
            e = e->next;
        }
    }

    T at(size_t i) const {
        if (i > this->size) {
            throw std::out_of_range("Index out of range.");
        }
        LLElem<T> *e = this->head;
        if (i <= (this->size / 2)) {
            e = this->head;
            for (int x = 0; x < i; x++) {
                e = e->next;
            }
        } else {
            e = this->tail;
            for (size_t x = 1; x < this->get_length()-i; x++) {
                e = e->prev;
            }
        }
        return e->value;
    }
    size_t get_length() const { return this->size; }

    T operator[](size_t i) const {
        return this->at(i);
    }

private:
    LLElem<T> *head = nullptr;
    LLElem<T> *tail = nullptr;
    size_t size = 0;
};

template<typename T>
std::ostream& operator<<(std::ostream& o, LinkedList<T> &a) {
    o << "{";
    for(size_t i = 0; i < a.get_length(); i++) {
        o << a.at(i);
        if (i < (a.get_length()-1)) {
            o << ",";
        }
    }
    o << "}";
    return o;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, LinkedList<T> *a) {
    o << *a;
    return o;
}
}
