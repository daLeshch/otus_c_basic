#ifndef SL_LIST_H
#define SL_LIST_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>


template<typename T>
class NodeSL {
    public:
        NodeSL<T>* next;
        T data;

        NodeSL(T value):data(value), next(nullptr){}
};

template<typename T>
class ListSL {
    public:
        ListSL();
        void push_back(T value);
        void append(T value);
        void insert(T value, size_t indx);
        void erase(size_t indx);
        size_t size()const;
        void print() const;
        T& operator [](size_t indx);
        ~ListSL();
        void debug_print_all() const;
        void debug_print_var(NodeSL<T>* var, std::string comment);

    private:
        NodeSL<T>* head;
        NodeSL<T>* tail;
        size_t list_size;
};

#endif
