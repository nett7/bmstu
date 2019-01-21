//
//  Queue.hpp
//  QUEUE
//
//  Created by Игорь on 26.04.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

#include <iostream>
#include <stdio.h>

struct Node {
    int data;
    Node* next;
};
template <typename T>
class FList {
    Node* first;
    Node* last;
public:
    auto empty_() -> bool;
    auto getlength() const ->size_t;
    auto getf() const -> Node* {return this->first;};
    auto getl() const -> Node* {return this->last;};
   
     auto insert(T val) -> void;
    /*
     auto remove(int val) -> bool;
     auto find(int val) const -> bool;
     auto change(int pos, int val) -> bool;
     auto print () const -> void;
     auto sort () ->void;
     auto addfirst(Node *node_) -> void;
     FList(Node *node_): first{ node_} {}
     */
    FList<T>() : first{ nullptr }, last{nullptr} {}
     ~FList<T>();
    
};
template <typename T>
auto FList<T>::insert(T val) -> void
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
template <typename T>
namespace Flist{
    class Queue {
    
public:
    //typedef int type;
    Queue<T>() {
        list = new FList<T>;
    }
   // Queue(std::initialer_list<T> list);
   // Queue<T>(const Queue& q);
  //  auto swap(Queue& q) -> void;
  //  auto operator=(const Queue& q);
    auto empty() -> bool;
    auto size() -> size_t;
    auto push(T) -> void;
 //   auto pop() -> void;
    auto front() -> T&;
    auto back() -> T&;
 //   bool operator==(const Queue& q);
 //   friend
 //   auto operator<<(ostream&, Queue&) -> ostream&;
 //   friend
 //   auto operator>>(istream&, Queue&) -> istream&;
   // ~Queue<T>();
    
private:
    FList<T>* list;
};}
template <typename T>
auto FList<T>::empty_()  -> bool
{
    if (first)
        return false;
    return true;
}
template <typename T>
auto FList<T>::getlength() const ->size_t
{
    if (empty_()) return 0;
    int i = 0;
    Node* working = first;
    for (;working->next!=nullptr;i++, working=working->next);
    return i;
}
/*auto Queue::swap(Queue& q) -> void{
 
 }*/
/*template <typename T>
 auto Queue::operator=(const Queue& q) -> Queue&{
 this -> swap (Queue{q});
 return *this;
 }*/

template <typename T>
auto Queue<T>::empty() -> bool{
    return list->empty_();
}
template <typename T>
auto Queue<T>::size() -> size_t{
    return FList<T>::list->getlength();
}
template <typename T>
auto Queue<T>::front() -> T&{
    return list->getf();
}
template <typename T>
auto Queue<T>::back() -> T&{
    return list->getl();
}
template <typename T>
auto  Queue<T>::push(T val) -> void{
    this->list->insert(val);
    
}
#endif /* Queue_hpp */
