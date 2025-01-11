#include "seqContainer.h"


template <typename T>
seqContainer<T>::seqContainer(size_t cap, bool rsv): cont_capacity(cap), cont_size(0), reserve(rsv)
{   if (reserve){
        cont_capacity *= 2;
        data = new T[cont_capacity];
        for (size_t i = 0; i < cont_capacity; ++i) {
            data[i] = T();
        }
}
    else {
        data = new T[cont_capacity];
        for (size_t i = 0; i < cont_capacity; ++i) {
            data[i] = T();
        }
    }
}

template <typename T>
void seqContainer<T>::push_back(T value) {
    if (reserve){
        if (cont_size == cont_capacity){
            cont_capacity *= 2;
            T* new_data = new T[cont_capacity];
            for (size_t i = 0; i < cont_size; i+=1){
                new_data[i] = data[i];
            }
            new_data[cont_size] = value;

            delete[] data;
            data = new_data;
        }
        else {
            data[cont_size] = value;
        }
        cont_size += 1;
    }
    else {
        T* new_data = new T[cont_size+1];
        for (size_t i = 0; i < cont_size; ++i){
            new_data[i] = data[i];
        }
        new_data[cont_size] = value;
        delete[] data;
        data = new_data;

        cont_size += 1;
    }
};

template <typename T>
void seqContainer<T>::append(T value) {
    if (!reserve){
        T* new_data = new T[cont_size+1];
        new_data[0] = value;
        for (size_t i = 0; i < cont_size; ++i){
            new_data[i+1] = data[i];
        }
        delete[] data;
        data = new_data;

        cont_size += 1;

    }
    else {
        if (cont_size == cont_capacity){
            cont_capacity *= 2;
            T* new_data = new T[cont_capacity];
            new_data[0] = value;
            for (size_t i = 0; i < cont_size; ++i){
                new_data[i+1] = data[i];
            }
            delete[] data;
            data = new_data;
            
            cont_size += 1;
        }
        else {
            for (size_t i = cont_size; i > 0; --i){
                data[i] = data[i-1];
            }
            data[0] = value;
            cont_size += 1;
        }
    }
};

template <typename T>
void seqContainer<T>::insert(T value, size_t indx)
{   if (indx >= cont_size){
        throw std::out_of_range("List index is out of range");
    }

    if (!reserve){
        T* new_data = new T[cont_size+1];

        for (size_t i = 0; i < indx; ++i){
            new_data[i] = data[i];
        }

        new_data[indx] = value;

        for (size_t i = indx; i < cont_size; ++i){
            new_data[i+1] = data[i];
        }

        delete[] data;
        data = new_data;

        cont_size += 1;

    }
    else {
        if (cont_size == cont_capacity){
            cont_capacity *= 2;
            
            T* new_data = new T[cont_capacity];

            for (size_t i = 0; i < indx; ++i){
                new_data[i] = data[i];
            }

            new_data[indx] = value;

            for (size_t i = indx; i < cont_size; ++i){
                new_data[i+1] = data[i];
            }

            delete[] data;
            data = new_data;

            cont_size += 1;
        }
        else {
            for (size_t i = cont_size; i > indx; --i) {
                data[i] = data[i - 1];
            }
            data[indx] = value;
            
            cont_size += 1;
        }
    }
}

template <typename T>
void seqContainer<T>::erase(size_t indx)
{   if (indx >= cont_size){
        throw std::out_of_range("List index is out of range");
    }

    for (size_t i = indx; i < cont_size - 1; ++i){
        data[i] = data[i+1];
    }
    
    cont_size -= 1;
}
template <typename T>
size_t seqContainer<T>::size() const
{
    return cont_size;
}

template <typename T>
size_t seqContainer<T>::capacity() const
{
    return cont_capacity;
}

template <typename T>
void seqContainer<T>::print() const
{   for (size_t i = 0; i < cont_size; ++i){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
T &seqContainer<T>::operator[](size_t indx)
{
    if (indx >= cont_size){
        throw std::out_of_range("List index is out of range");
    }

    return data[indx];
}

template <typename T>
seqContainer<T>::~seqContainer()
{   if (data != nullptr){
        delete[] data;
}
}
