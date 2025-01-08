#ifndef DL_LIST_H
#define DL_LIST_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>


template<typename T>
class Node {
    public:
        Node<T>* next;
        Node<T>* prev;
        T data;

        Node(T value):data(value), next(nullptr), prev(nullptr){}
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
        ~ListDL();

    private:
        Node<T>* head;
        Node<T>* tail;
        size_t list_size;

};

#endif
