#include "sl_list.h"

template <typename T>
ListSL<T>::ListSL(): head(nullptr), tail(nullptr), list_size(0)
{ 
};

template<typename T>
ListSL<T>::~ListSL(){
    NodeSL<T>* current = head;
    while (current != nullptr){
        NodeSL<T>* next = current->next;
        delete current;
        current = next;
    }
};

template<typename T>
void ListSL<T>::push_back(T value)
{   NodeSL<T>* newNode = new NodeSL<T>(value);
    if (tail){
        tail->next = newNode;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
    list_size += 1;
};

template<typename T>
void ListSL<T>::append(T value)
{   NodeSL<T>* newNode = new NodeSL<T>(value);
    if (head){
        newNode->next = head;
        head = newNode;
    }
    else {
        head = tail = newNode;
    }
    list_size += 1;
};

template<typename T>
void ListSL<T>::insert(T value, size_t indx)
{   if (indx > list_size){
        throw std::out_of_range("List index out of range");
        }
    
    NodeSL<T>* current = head;
    NodeSL<T>* newNode = new NodeSL<T>(value);

    if (indx == 0){
        newNode->next = head->next;
        head = newNode;
    }
    
    else {
        NodeSL<T>* prev = nullptr;

        for (size_t current_indx = 0; current_indx < indx; ++current_indx){
            prev = current;
            current = current->next;
        }
        newNode->next = current;
        prev->next = newNode;

    }

        list_size += 1;
    
};

template<typename T>
void ListSL<T>::erase(size_t indx)
{   if (indx > list_size){
        throw std::out_of_range("List index out of range");
        }
    

    NodeSL<T>* current = head;

    if (indx == 0){
        head = head->next;
        delete current;
    }
    
    else {
        NodeSL<T>* prev = nullptr;

        for (size_t current_indx = 0; current_indx < indx; ++current_indx){
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
    }



    list_size -= 1;
};

template<typename T>
size_t ListSL<T>::size() const
{
    return list_size;
};

template <typename T>
void ListSL<T>::print() const {
    NodeSL<T>* current = head;
    while (current){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
};

template <typename T>
void ListSL<T>::debug_print_all() const {
    NodeSL<T>* current = head;
    while (current){
        T current_nx = current->next ? current->next->data : -666;
        std::cout << "  data: " << current->data << " next: " << current_nx <<"\n";
        current = current->next;
    }
    std::cout << "\n";
};

template <typename T>
void ListSL<T>::debug_print_var(NodeSL<T>* var, std::string comment) {
    if (var){
        T current = var->data;
        T current_nx = var->next ? var->next->data : -666;
        std::cout << current << "  next: " << current_nx << " : " << comment << "\n";
    }
    else {
        std::cout << "node is nullptr here: " << comment << "\n";
    }
};
