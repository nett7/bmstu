//
//  ForwardList.cpp
//  23
//
//  Created by Игорь on 02.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//
#include "ForwardList.hpp"



struct Node;
//void yell_error();

auto ForwardList::insert(int val) -> void {
        //insetion to end of list
        
        if (first == nullptr) {
            //yell_error();
            std::cout << "error";
            return;
        }
        Node *working = first;
        while(working->next != nullptr){
            working=working->next;
        }
        working->next = new Node{val, nullptr};
}

auto ForwardList::remove(int val) -> bool {
        if (first == nullptr) {
            //yell_error();
            std::cout << "error";
            return 0;
        }
        Node *working = first;
    if (first -> data == val) {
        //yell_error();
        Node * temp = first;
        first = first->next;
        delete temp;
        return 0;
    }
        while (working != nullptr) {
            if (working->next->data == val) {
                delete working->next;
                working->next = nullptr;
                return 1;
            }
            working=working->next;
        }
        return 0;
}
    
auto ForwardList::print() -> void {
        if (first == nullptr) {
            //yell_error();
            std::cout << "error";
        }
        Node *working = first;
        while (working != nullptr) {
            std::cout << working->data<< std::endl;
            working=working->next;
            }
}

ForwardList::ForwardList(Node *node_) {
                first = node_; // this -> {ptr = "nullptr", size = 0}
}
ForwardList::~ForwardList() {
    for (Node *temp = first ;temp!=nullptr; temp = temp->next){
        delete temp;
    }
}
