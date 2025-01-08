#include "dl_list.h"
#include "vector.h"
#include <iostream>



int main(){
    ListDL<int> values;

    for (int i = 0; i <= 9; i++){
        values.push_back(i);
    }
    std::cout << "Doubly Linked List - FILLED:" << "\n";
    values.print();

    std::cout << "Doubly Linked List - SIZE:" << "\n"<< values.size()<<"\n";

    values.erase(6);
    values.erase(4);
    values.erase(2);

    std::cout << "Doubly Linked List - ERASE ELEMENTS BY INDEXES 2, 4, 6:" << "\n";
    values.print();

    values.append(10);
    std::cout << "Doubly Linked List - APPEND 10:" << "\n";
    values.print();

    values.insert(20, 4);
    std::cout << "Doubly Linked List - INSERT 20 IN THE MIDDLE:" << "\n";
    values.print();

    values.push_back(30);
    std::cout << "Doubly Linked List - PUSH BACK 30:" << "\n";
    values.print();
}