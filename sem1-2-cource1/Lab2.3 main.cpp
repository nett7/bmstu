//
//  main.cpp
//  23
//
//  Created by Игорь on 02.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#include "ForwardList.hpp"
struct Node;


int main(int argc, const char * argv[]) {
    
    ForwardList list{new Node{1, nullptr}};
    list.print();
    list.insert(2);
    list.print();
    list.remove(1);
    list.print();
}
