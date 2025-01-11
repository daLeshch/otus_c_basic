#ifndef SEQCONTAINER_H
#define SEQCONTAINER_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>

template<typename T>
class seqContainer {
    public:
        seqContainer(size_t cap, bool rsv = false);
        void push_back(T value);
        void append(T value);
        void insert(T value, size_t indx);
        void erase(size_t indx);
        size_t size()const;
        size_t capacity()const;
        void print() const;
        T& operator [](size_t indx);
        ~seqContainer();

    private:
        T* data;
        size_t cont_capacity;
        size_t cont_size;
        bool reserve;
        
};


#endif

