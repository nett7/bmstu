//
//  FList.hpp
//  FList
//
//  Created by Игорь on 11.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#ifndef FList_hpp
#define FList_hpp
#include <iostream>
#include <stdio.h>

#endif /* FList_hpp */
struct Node {
    int data;
    Node* next;
};
class FList {
    Node* first;
public:
    auto empty() const -> bool;
    auto getlength() const ->int;
    auto insert(int val) -> void;
    auto remove(int val) -> bool;
    auto find(int val) const -> bool;
    auto change(int pos, int val) -> bool;
    auto print () const -> void;
    auto sort () ->void;
    auto addfirst(int val) -> void;
    auto reverse() -> void;
    auto swap(FList tree) -> void {
        std::swap(first, tree.first);
    }
    FList(Node *node_): first{ node_} {}
    FList() : first{ nullptr } {}
    ~FList();
};
