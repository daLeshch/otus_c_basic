#include "dl_list.cpp"
#include "sl_list.cpp"
#include "vector.h"
#include <iostream>



int main(){
    ListDL<int> dl_list;

    for (int i = 0; i <= 9; i++){
        dl_list.push_back(i);
    }
    std::cout << "Doubly Linked List - FILLED:" << "\n";
    dl_list.print();
    // dl_list.debug_print_all();

    std::cout << "\nDoubly Linked List - SIZE:" << "\n"<< dl_list.size()<<"\n";

    dl_list.erase(6);
    dl_list.erase(4);
    dl_list.erase(2);

    std::cout << "\nDoubly Linked List - ERASE ELEMENTS BY INDEXES 2, 4, 6:" << "\n";
    dl_list.print();
    // dl_list.debug_print_all();

    dl_list.append(10);
    std::cout << "\nDoubly Linked List - APPEND 10:" << "\n";
    dl_list.print();

    dl_list.insert(20, 4);
    std::cout << "\nDoubly Linked List - INSERT 20 IN THE MIDDLE:" << "\n";
    dl_list.print();

    dl_list.push_back(30);
    std::cout << "\nDoubly Linked List - PUSH BACK 30:" << "\n";
    dl_list.print();

    std::cout << "\n_____________________________________________________________________________________________________\n";

    ListSL<int> sl_list;

    for (int i = 0; i <= 9; i++) {
        sl_list.push_back(i);
    }
    std::cout << "Singly Linked List - FILLED:" << "\n";
    sl_list.print();
    // sl_list.debug_print_all();

    std::cout << "\nSingly Linked List - SIZE:" << "\n" << sl_list.size() << "\n";

    sl_list.erase(6);
    sl_list.erase(4);
    sl_list.erase(2);

    std::cout << "\nSingly Linked List - ERASE ELEMENTS BY INDEXES 2, 4, 6:" << "\n";
    sl_list.print();
    // sl_list.debug_print_all();

    sl_list.append(10);
    std::cout << "\nSingly Linked List - APPEND 10:" << "\n";
    sl_list.print();

    sl_list.insert(20, 4);
    std::cout << "\nSingly Linked List - INSERT 20 IN THE MIDDLE:" << "\n";
    sl_list.print();

    sl_list.push_back(30);
    std::cout << "\nSingly Linked List - PUSH BACK 30:" << "\n";
    sl_list.print();

}