#include "dl_list.h"

template <typename T>
ListDL<T>::ListDL(): head(nullptr), tail(nullptr), list_size(0)
{ 
};

template<typename T>
ListDL<T>::~ListDL(){
    Node<T>* current = head;
    while (current != nullptr){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
};

template<typename T>
void ListDL<T>::push_back(T value)
{   Node<T>* newNode = new Node<T>(value);
    if (tail){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
    list_size += 1;
};

template<typename T>
void ListDL<T>::append(T value)
{   Node<T>* newNode = new Node<T>(value);
    if (head){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    else {
        head = tail = newNode;
    }
    list_size += 1;
};

template<typename T>
void ListDL<T>::insert(T value, size_t indx)
{   if (indx > list_size){
        throw std::out_of_range("List index out of range");
        }
    
    Node<T>* newNode = new Node<T>(value);

    if (indx == 0){
        newNode->next = head;
        if (head){
            head->prev = newNode;
        }
        head = newNode;
        if (!tail){
            tail = newNode;
        }
        list_size += 1;
    }

    else if (indx == list_size){
        newNode->prev = tail;
        if (tail){
            tail->next = newNode;
        }
        tail = newNode;
        list_size += 1;
    }

    else{
        Node<T>* current = head;
        size_t current_indx = 0;
            T cur_h = current->data;
            std::cout << cur_h << " - head current value in while cycle\n";
        while (current_indx < indx){
            current = current->next;
            current_indx++;
            T cur_w = current->data;
            std::cout << cur_w << " - current value in while cycle\n";
            T cur_pr_old2 = current->prev->data;
            std::cout << cur_pr_old2 << " - old current prev value in insert func\n";
        }
        T cur = current->data;
        std::cout << cur << " - current value in insert func\n";

        T cur_pr_old = current->prev->data;
        std::cout << cur_pr_old << " - old current prev value in insert func\n";

        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev){
            current->prev->next = newNode;
        }

        newNode->prev->next = newNode;


        T cur_pr = current->prev->data;
        std::cout << cur_pr << " - current->prev value in insert func\n";


        T nn_pr = newNode->prev->data;
        std::cout << nn_pr << " - newNode->prev value in insert func\n";
        
        T pr_nx = newNode->prev->next->data;
        std::cout << pr_nx << " - newNode->prev->next value in insert func\n";

        list_size += 1;
    }
};

template<typename T>
void ListDL<T>::erase(size_t indx)
{   if (indx > list_size){
        throw std::out_of_range("List index out of range");
        }
    

    if (indx == 0){
        Node<T>* temp = head;
        head = temp->next;
        if (head){
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;

    }

    else if (indx == list_size-1){
        Node<T>* temp = tail;
        tail = temp->prev;
        if (tail){
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }

    else{
        Node<T>* current = head;
        size_t current_indx = 0;

        while (current_indx < indx){
            current = current->next;
            current_indx++;
        }

        if (current->prev){
            current->prev->next = current->next;
        }
        else if (current->next){
            current->next->prev = current->prev;
        }
        delete current;
    }

    list_size -= 1;
};

template<typename T>
size_t ListDL<T>::size() const
{
    return list_size;
};

template <typename T>
void ListDL<T>::print() const {
    Node<T>* current = head;
    while (current){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
};
