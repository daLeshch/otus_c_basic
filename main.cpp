#include "dl_list.cpp"
#include "sl_list.cpp"
#include "seqContainer.cpp"

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
    
    int dl_list_element = dl_list[3];
    std::cout << "\nDoubly Linked List - GET ELEMENT BY INDEX 3: " << "\n";
    std::cout << "This is the 4th element in the list:" << dl_list_element << "\n";

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

    int sl_list_element = sl_list[3];
    std::cout << "\nSingly Linked List - GET ELEMENT BY INDEX 3: " << "\n";
    std::cout << "This is the 4th element in the list:" << sl_list_element << "\n";


    std::cout << "\n_____________________________________________________________________________________________________\n";

    seqContainer<int> seq_container(10, false);
    std::cout << "\nsequence container WITHOUT MEMORY RESERVATION CREATED - CAPACITY:" << "\n" << seq_container.capacity() << "\n";

    for (int i = 0; i <= 9; i++) {
        seq_container.push_back(i);
    }
    std::cout << "\nsequence container - FILLED:" << "\n";
    seq_container.print();


    std::cout << "\nsequence container - SIZE:" << "\n" << seq_container.size() << "\n";

    seq_container.erase(6);
    seq_container.erase(4);
    seq_container.erase(2);

    std::cout << "\nsequence container - ERASE ELEMENTS BY INDEXES 2, 4, 6:" << "\n";
    seq_container.print();


    seq_container.append(10);
    std::cout << "\nsequence container - APPEND 10:" << "\n";
    seq_container.print();

    seq_container.insert(20, 4);
    std::cout << "\nsequence container - INSERT 20 IN THE MIDDLE:" << "\n";
    seq_container.print();

    seq_container.push_back(30);
    std::cout << "\nsequence container - PUSH BACK 30:" << "\n";
    seq_container.print();

    int seq_container_element = seq_container[3];
    std::cout << "\nsequence container - GET ELEMENT BY INDEX 3: " << "\n";
    std::cout << "This is the 4th element in the list:" << seq_container_element << "\n";


    std::cout << "\n_____________________________________________________________________________________________________\n";

    seqContainer<int> seq_container_rsv(10, true);
    std::cout << "\nsequence container WITH MEMORY RESERVATION CREATED - CAPACITY:" << "\n" << seq_container_rsv.capacity() << "\n";

    for (int i = 0; i <= 9; i++) {
        seq_container_rsv.push_back(i);
    }
    std::cout << "\nsequence container - FILLED:" << "\n";
    seq_container_rsv.print();


    std::cout << "\nsequence container - SIZE:" << "\n" << seq_container_rsv.size() << "\n";

    seq_container_rsv.erase(6);
    seq_container_rsv.erase(4);
    seq_container_rsv.erase(2);

    std::cout << "\nsequence container - ERASE ELEMENTS BY INDEXES 2, 4, 6:" << "\n";
    seq_container_rsv.print();


    seq_container_rsv.append(10);
    std::cout << "\nsequence container - APPEND 10:" << "\n";
    seq_container_rsv.print();

    seq_container_rsv.insert(20, 4);
    std::cout << "\nsequence container - INSERT 20 IN THE MIDDLE:" << "\n";
    seq_container_rsv.print();

    seq_container_rsv.push_back(30);
    std::cout << "\nsequence container - PUSH BACK 30:" << "\n";
    seq_container_rsv.print();

    int seq_container_rsv_element = seq_container_rsv[3];
    std::cout << "\nsequence container - GET ELEMENT BY INDEX 3: " << "\n";
    std::cout << "This is the 4th element in the list:" << seq_container_element << "\n";
}