#include "dl_list.h"

template <typename T>
ListDL<T>::ListDL(): head(nullptr), tail(nullptr), list_size(0)
{ 
};

template<typename T>
ListDL<T>::~ListDL(){
    NodeDL<T>* current = head;
    while (current != nullptr){
        NodeDL<T>* next = current->next;
        delete current;
        current = next;
    }
};

template<typename T>
void ListDL<T>::push_back(T value)
{   NodeDL<T>* newNode = new NodeDL<T>(value);
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
{   NodeDL<T>* newNode = new NodeDL<T>(value);
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
    
    NodeDL<T>* newNode = new NodeDL<T>(value);
    // debug_print_var(newNode, "newNode created, 52 line, Insert func beginning\n");
    if (indx == 0){
        newNode->next = head;
        // debug_print_var(newNode->next, "first IF statement, changed newNode->next to head, 55 line\n");
        if (head){
            head->prev = newNode;
            // debug_print_var(head->prev, "head->prev in case of head exist, first IF statement \n");
        }
        head = newNode;
        // debug_print_var(head, "head changed to newNode, first IF \n");
        if (!tail){
            tail = newNode;
            // debug_print_var(tail, "tail changed to newNode, first IF in case there was no tail \n");
        }
        list_size += 1;
    }

    else if (indx == list_size){
        newNode->prev = tail;
        // debug_print_var(newNode->prev, "newNode->prev chaged to tail, ELSE IF \n");
        if (tail){
            tail->next = newNode;
            // debug_print_var(tail->next, "tail->next changed to newNode in case of tail existing, ELSE IF \n");
        }
        tail = newNode;
        // debug_print_var(tail, "tail changed to newNode, ELSE IF\n");
        list_size += 1;
    }

    else{
        // debug_print_var(head, "just head, MAIN BODY\n");
        NodeDL<T>* current = head;
        // debug_print_var(current, "current created and assigned as head, MAIN BODY\n");
        size_t current_indx = 0;
        // std::cout << "current index in the beginning" << current_indx << "\n";
        
        while (current_indx < indx){
            current = current->next;
            // debug_print_var(current, "current, MAIN BODY, WHILE CYCLE\n");
            // debug_print_var(current->prev, "current->prev, MAIN BODY, WHILE CYCLE\n");
            // debug_print_var(current->next, "current->next, MAIN BODY, WHILE CYCLE\n");
            current_indx++;
            // std::cout << "\n__________________________________\n\n";
        }
        // debug_print_var(current, "current right after while cycle, MAIN BODY\n");
        // debug_print_var(current->prev, "current->prev right after while cycle, MAIN BODY\n");
        // debug_print_var(current->next, "current->next right after while cycle, MAIN BODY\n");

        newNode->prev = current->prev;
        // debug_print_var(newNode->prev, "changed newNode->prev to current->prev, MAIN BODY\n");
        newNode->next = current;
        // debug_print_var(newNode->next, "changed newNode->next to current, MAIN BODY\n");
        if (current->prev){
            current->prev->next = newNode;
            // debug_print_var(current->prev->next, "changed current->prev->next to newNode in case of current->prev existing, MAIN BODY\n");
        }

        newNode->prev->next = newNode;
        // debug_print_var(newNode->prev->next, "changed newNode->prev->next to newNode, MAIN BODY\n");


        list_size += 1;
    }
};

template<typename T>
void ListDL<T>::erase(size_t indx)
{   if (indx > list_size){
        throw std::out_of_range("List index out of range");
        }
    

    NodeDL<T>* current = head;

    for (size_t current_indx = 0; current_indx < indx; ++current_indx){
        current = current->next;
    }

    if (current->prev){
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next){
        current->next->prev = current->prev;
    }
    else {
        tail = current->prev;
    }
    
    delete current;

    list_size -= 1;
};

template<typename T>
size_t ListDL<T>::size() const
{
    return list_size;
};

template <typename T>
void ListDL<T>::print() const {
    NodeDL<T>* current = head;
    while (current){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
};

template <typename T>
void ListDL<T>::debug_print_all() const {
    NodeDL<T>* current = head;
    while (current){
        T current_nx = current->next ? current->next->data : -666;
        T current_pv = current->prev ? current->prev->data : -666;
        std::cout << " prev: " << current_pv << "  data: " << current->data << " next: " << current_nx <<"\n";
        current = current->next;
    }
    std::cout << "\n";
};

template <typename T>
void ListDL<T>::debug_print_var(NodeDL<T>* var, std::string comment) {
    if (var){
        T current = var->data;
        T current_nx = var->next ? var->next->data : -666;
        T current_pv = var->prev ? var->prev->data : -666;
        std::cout << "  prev: " << current_pv << "   data: " << current << "  next: " << current_nx << " : " << comment << "\n";
    }
    else {
        std::cout << "node is nullptr here: " << comment << "\n";
    }
};
