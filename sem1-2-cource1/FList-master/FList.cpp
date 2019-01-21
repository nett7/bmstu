//
//  FList.cpp
//  FList
//
//  Created by Игорь on 11.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#include "FList.hpp"
using namespace std;

struct Node;
auto FList::empty() const -> bool
{
    if (first)
        return false;
    return true;
}
auto FList::getlength() const ->int
{
    if (empty()) return 0;
    int i = 0;
    Node* working = first;
    for (;working->next!=nullptr;i++, working=working->next);
    return i;
}

auto FList::insert(int val) -> void
{
    if (first == nullptr)
    {
        first = new Node{ val, nullptr };
        return;
    }
    Node* working = first;
    while (working->next != nullptr) {
        working = working->next;
    }
    working->next = new Node{ val, nullptr };
}

auto FList::remove(int val) -> bool
{
    Node* working = first;
    bool flag = 0;
    while (working && working->next != nullptr) {
        if (working->data == val)
            flag = 1;
            working = working->next;
            }
    if (flag == 0)
        return false;
    
    /*if (first == nullptr) {
     cout << "error" << endl;
     return 1;
     }*/
    if (first->data == val) {
        
        Node* temp = first;
        first = first->next;
        delete temp;
        return true;
    }
    working = first;
    while (working && (working->next->data != val)) {
        working = working->next;
    }
    Node* DEL = working->next;
    working->next = DEL->next;
    delete DEL;
    return true;
}

auto FList::print() const -> void
{
    
    Node* temp = first;
    if (first == nullptr) {
        std::cout << "список пуст" << std::endl;
        return;
        }
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
        }
        
        auto FList::find(int val) const -> bool
        {
            Node* working = first;
            bool flag = 0;
            int i = 1;
            while (working) {
                if (working->data == val) {
                    flag = 1;
                    cout << i << " ";
                }
                i++;
                working = working->next;
            }
            if (flag)
                cout << endl;
            return flag;
        }
        
        auto FList::change(int pos, int val) -> bool
        {
            Node* working = first;
            if ((pos < 1) or (pos > getlength())) return 0;
            for(unsigned int i = 1; i != pos; i++, working=working->next);
            working->data = val;
            return true;
        }
        
        auto FList::sort() ->void{

            if (first->next==nullptr) return; //если список из одного элемента, то он сам по себе отсортирован
            for (Node *node = first; node; node =node->next)
                for(Node *node2 = first; node2; node2=node2->next)
                    if(node->data < node2-> data) {
                        int temp = node->data;
                        node->data = node2->data;
                        node2->data = temp;
                    }
        }
        auto FList::addfirst(int val) -> void{
            Node* node_=new Node;
            node_->data = val;
            Node* working = first;
            first = node_;
            node_->next=working;
            
        }
        auto FList::reverse() -> void{
            if (first->next==nullptr) return;
            FList temp;
            Node*working = first;
            for(int i = 0; i <= this->getlength(); i++) {
                
                temp.addfirst(working->data);
                working=working->next;
            }
            
            this->swap(temp);
            temp.first = nullptr;
        }
        
        FList::~FList()
        {
            for (Node* temp = first; temp != nullptr; temp = temp->next) {
                delete temp;
            }
        }

