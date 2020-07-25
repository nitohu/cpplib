#include <stdexcept>
#include <initializer_list>
#include <string>

class IntArrayElement  {
public:
    IntArrayElement() {}
    IntArrayElement(int x) {
        this->value = x;
    }

    int value;
    IntArrayElement *next = nullptr;
    IntArrayElement *prev = nullptr;
};

class IntArray {
public:
    IntArray() {}
    IntArray(std::initializer_list<int> l) {
        for (auto i = l.begin(); i != l.end(); i++) {
            this->append(*i);
        }
    }
    ~IntArray() {
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
        IntArrayElement *e = new IntArrayElement(x);
        e->next = this->head;
        this->head->prev = e;
        this->head = e;
        this->size++;
    }

    void append(int x) {
        IntArrayElement *e = new IntArrayElement(x);
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

    void cut(unsigned int x, unsigned int y) {
        if (x > this->get_length() || y > this->get_length()) {
            throw "x or y is out of range.";
        }
        if (this->get_length() < 2) {
            throw "Length must be bigger than 2.";
        }
        if (x > y) {
            throw "x must be smaller than y.";
        }
        IntArrayElement *e = this->head;
        for (unsigned int i = 0; i < y; i++) {
            if (i >= x) {
                IntArrayElement *prev = e->prev;
                IntArrayElement *next = e->next;
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

    int at(unsigned int i) {
        if (i > this->size) {
            throw std::out_of_range("Index out of range.");
        }
        IntArrayElement *e = this->head;
        if (i <= (this->size / 2)) {
            e = this->head;
            for (int x = 0; x < i; x++) {
                e = e->next;
            }
        } else {
            e = this->tail;
            for (int x = 1; x < this->get_length()-i; x++) {
                e = e->prev;
            }
        }
        return e->value;
    }
    int get_length() { return this->size; }

    int operator [](unsigned int i) {
        return this->at(i);
    }
private:
    IntArrayElement *head = nullptr;
    IntArrayElement *tail = nullptr;
    int size = 0;
};

std::ostream& operator<<(std::ostream& o, IntArray *a) {
    o << "{";
    for(int i = 0; i < a->get_length(); i++) {
        o << a->at(i);
        if (i < (a->get_length()-1)) {
            o << ",";
        }
    }
    o << "}";
    return o;
}
