//
//  ForwardList.hpp
//  23
//
//  Created by Игорь on 02.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#ifndef ForwardList_hpp
#define ForwardList_hpp
#include <iostream>
#include <stdio.h>

#endif /* ForwardList_hpp */
struct Node {
    int data;
    Node* next;
};
//void yell_error() { std::cout << "error";}
class ForwardList {
    Node* first;
public:
    auto insert(int val) -> void;
    auto remove(int val) -> bool;
    auto print() -> void;
    ForwardList(Node *node_);
    ~ForwardList();
};

