#ifndef DL_LIST_H
#define DL_LIST_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>


template<typename T>
class NodeDL {
    public:
        NodeDL<T>* next;
        NodeDL<T>* prev;
        T data;

        NodeDL(T value):data(value), next(nullptr), prev(nullptr){}
};

template<typename T>
class ListDL {
    public:
        ListDL();
        void push_back(T value);
        void append(T value);
        void insert(T value, size_t indx);
        void erase(size_t indx);
        size_t size()const;
        void print() const;
        T& operator [](size_t indx);
        ~ListDL();
        void debug_print_all() const;
        void debug_print_var(NodeDL<T>* var, std::string comment);

    private:
        NodeDL<T>* head;
        NodeDL<T>* tail;
        size_t list_size;
};

#endif
