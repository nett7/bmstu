//
//  BSTree.cpp
//  BSTree
//
//  Created by Игорь on 30.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//
/*
#include "BSTree.hpp"
#include <fstream>
#include <cstring>
#include <sstream>
#include <unistd.h>
template <typename T>
struct Node;
template <typename T>
auto Tree::look_for_val(T val) const -> bool
{
    if (root == nullptr)
        return false;
    Node<T>* node = root;
    while (node->data != val) {
        if (node->data > val)
            node = node->left;
            else
                node = node->right;
                if (node == nullptr)
                    return false;
    }
    return true;
    Node* working = root;
     while (working->data != val){
     if(working == nullptr) return false;
     if(working->data<val) working= working->right;
     else working=working->left;
     if (root->data == val) return true;
     }
     return true;*/
    /*for(; working->data != val;
     working->data>val?
     working= working->right:
     working=working->left)
     if(working == nullptr) return false;
     return true;
}
auto Tree::clean(Node*& node) -> void
{
    //use reverse met.
    if(node != nullptr) {
        clean(node->left);
        clean(node->right);
        delete node;
    }
    node = nullptr;
}
auto Tree::direct_print(Node* node) const -> void
{
    if (node == nullptr)
        return;
    std::cout << node->data << ' ';
    direct_print(node->left);
    direct_print(node->right);
    }
    auto Tree::symmetric_print(Node* node) const -> void
    {
        if (node == nullptr)
            return;
        symmetric_print(node->left);
        std::cout << node->data << ' ';
        symmetric_print(node->right);
    }
    auto Tree::reverse_print(Node* node) const -> void
    {
        if (node == nullptr)
            return;
        direct_print(node->left);
        direct_print(node->right);
        std::cout << node->data << ' ';
    }
    auto Tree::list(order ord) const -> void
    {
        switch (ord) {
            case order::direct:
                direct_print(root);
                break;
            case order::symmetric:
                symmetric_print(root);
                break;
            case order::reverse:
                reverse_print(root);
                break;
        };
    }
    
     auto direct_print(const Tree *) ->void{
     
     }
     auto symmetric_print(const Tree *) ->void{
     
     }
     auto reverse_print(const Tree *) ->void{
     
     }
    auto print_(int depth, Node* node) -> void
    {
        if (node == nullptr) {
            if (depth == 0)
                cout << "список пуст" << endl;
            return;
        }
        for (int i = 0; i < depth; i++, cout << "~~")
            ;
        cout << node->data << endl;
        print_(depth + 1, node->left);
        print_(depth + 1, node->right);
    }
    
    auto Tree::return_root() -> Node * {
     return (root);
     }
    auto Tree::insert(int val) -> void
    {
        if (root == nullptr) { // empty tree -> add root
            root = new Node{ val };
            return;
        }
        // only if tree if not empty:
        Node* working = root;
        Node* parental = working;
        while (working != nullptr) {
            if (working->data == val)
                throw logic_error("уже есть"); // there should be only one branch/leaf with any value
            if (working->data > val) {
                parental = working;
                working = working->left;
            }
            else {
                parental = working;
                working = working->right;
            }
            //exit if leaf/branch allready exists or found parental node for new node (working== nullptr)
        }
        if (parental->data < val)
            parental->right = new Node{ val };
        else
            parental->left = new Node{ val };
        return;
    }
    auto print_to(Node* node, ofstream& f) -> void
    {
        if (node == nullptr)
            return;
        f << node->data << ' ';
        print_to(node->left, f);
        print_to(node->right, f);
    }
    auto Tree::save(std::string& filename) -> bool
    {
     
         int access(const char *path, int amode);
         amode :
         F_OK - существование
         R_OK,
         W_OK,
         X_OK
         
        //if (!(access(filename.c_str(), W_OK)))
        //    throw logic_error(" нет прав на запись");
        if (!(access(filename.c_str(), F_OK))) {
            std::string answer;
            std::cout << "Перезаписать файл? (Да|Нет)" << std::endl;
            std::cin >> answer;
            if (answer == "Да") {
                std::ofstream fout(filename.c_str());
                print_to(root, fout);
                fout.close();
                return true;
            }
            else
                return false;
        }
        else {
            std::ofstream fout(filename.c_str());
            print_to(root, fout);
            fout.close();
            return true;
        }
    }
    auto Tree::load(std::string &filename) -> bool{
        //if (!(access(filename.c_str(), F_OK))) {
          //  throw logic_error("файла нет");
        //}
        //if (!(access(filename.c_str(), R_OK)))
        //    throw logic_error(" нет прав на запись");
        
            std::ifstream fin(filename.c_str());
            this->clean(root);
            int value;
            fin >> value;
            if(!fin)
                return false;
            while(fin) {
                this->insert(value);
                fin >> value;
            }
            fin.close();
            return true;
        
    }
    auto Tree::remove(int val) -> void
    {
        if (!look_for_val(val))
            throw logic_error("такого значения найдено не было");
        Node* working_parent = nullptr;
        Node* working = root;
        Node* pruned = nullptr;
        
        while (working->data != val) {
            working_parent = working;
            if (val > working->data)
                working = working->right;
            else
                working = working->left;
        } //after this loop i would have val in form of working->data == val
        if (!(working->left) || !(working->right)) {
            Node* needed_child = nullptr;
            if (working->right)
                needed_child = working->right;
            else if (working->left)
                needed_child = working->left;
            if (!(working_parent))
                root = needed_child; //(!(working->left) && !(working->right))
            else if (working_parent->right == working)
                working->right = needed_child;
            else
                working->left = needed_child;
        }
        else {
            Node* most_left = working->right;
            Node* most_left_parent = working;
            while (most_left->left != nullptr) {
                most_left_parent = most_left;
                most_left = most_left->left;
            }
            working->data = most_left->data;
            pruned = most_left;
            if (most_left_parent->left == most_left)
                most_left_parent->left = nullptr;
            else
                most_left_parent->right = most_left->right;
        }
        delete pruned;
    }
*/
