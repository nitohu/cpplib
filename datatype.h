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

    int at(int i) {
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

    int operator [](int i) {
        return this->at(i);
    }

    std::ostream& operator <<(std::ostream& o) {
        std::string s = "{";
        for(int i = 0; i < this->get_length(); i++) {
            s += std::to_string(s.at(i));
            if (i < (this->get_length()-1)) {
                s += ",";
            }
        }
        s += "}";
        std::cout << s << std::endl;
        o << s;
        return o;
    }
private:
    IntArrayElement *head = nullptr;
    IntArrayElement *tail = nullptr;
    int size = 0;
};

