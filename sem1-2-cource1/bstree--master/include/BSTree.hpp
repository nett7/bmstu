//
//  BSTree.hpp
//  BSTree
//
//  Created by Игорь on 30.03.18.
//  Copyright © 2018 Игорь. All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp

#include <stdio.h>
#include <fstream>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

#endif /* BSTree_hpp */
template <typename T>
struct Node {
    T data;
    
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    Node(int val)
    : left(nullptr)
    , right(nullptr)
    , parent(nullptr)
    {
        data = val;
    }
    
    static auto next(Node<T>*) -> Node<T>*;
    static auto prev(Node<T>*) -> Node<T>*;
    static auto min(Node<T>*) -> Node<T>*;
    static auto max(Node<T>*) -> Node<T>*;
};

template <typename T>
auto print_(int depth, Node<T>* node) -> void;
template <typename T>
auto print_to(Node<T>* node, ofstream& f) -> void;
template <typename T>
auto remove_(Node<T>* node, int val, Node<T>* perent) -> void;

template <typename T>
class Bdi : public std::iterator<std::bidirectional_iterator_tag, Node<T> > {
private:
    Node<T>* pointer;
public:
    Bdi(Node<T>* ptr = nullptr);
    auto operator++() -> Bdi<T>&;
    auto operator++(int) -> Bdi<T>;
    auto operator--() -> Bdi<T>&;
    auto operator--(int) -> Bdi<T>;
    auto operator*() const -> T&;
    auto operator==(const Bdi& other) -> bool;
    auto operator!=(const Bdi& other) -> bool;
    auto swap(Bdi& rhs) -> void;
};

template <typename T>
Bdi<T>::Bdi(Node<T>* ptr)
: pointer{ ptr }
{};

template <typename T>
auto Node<T>::min(Node<T>* node) -> Node<T> *
{
    if( !node ) {
        return nullptr;
    }
    
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

template <typename T>
auto Node<T>::max(Node<T>* node) -> Node<T> *
{
    if( !node ) {
        return nullptr;
    }
    
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

template <typename T>
auto Node<T>::next(Node<T>* node) -> Node<T> *
{
    if( !node ) {
        return nullptr;
    }
    
    if (node->right != nullptr)
        return min(node->right);
    Node<T>* parent_ = node->parent;
    while (parent_ != nullptr && node == parent_->right) {
            node = parent_;
            parent_ = parent_->parent;
    }
    return parent_;
}

template <typename T>
auto Node<T>::prev(Node<T>* node) -> Node<T> *
{
    if( !node ) {
        return nullptr;
    }
    
    if (node->left != nullptr)
        return max(node->left);
        Node<T>* parent_ = node->parent;
        while (parent_ != nullptr && node == parent_->left) {
            node = parent_;
            parent_ = parent_->parent;
        }
    return parent_;
}

template <typename T>
auto Bdi<T>::operator++() -> Bdi<T> &
{
    pointer = Node<T>::next(pointer);
    return *this;
}

template <typename T>
auto Bdi<T>::operator++(int) -> Bdi<T>
{
    Bdi<T> before(pointer);
    ++(*this);
    return before;
}

template <typename T>
auto Bdi<T>::operator--() -> Bdi<T> &
{
    pointer = Node<T>::prev(pointer);
    return *this;
}

template <typename T>
auto Bdi<T>::operator--(int) -> Bdi<T>
{
    Bdi<T> before(pointer);
    --(*this);
    return before;
}

template <typename T>
auto Bdi<T>::operator*() const -> T &
{
    return pointer->data;
}

template <typename T>
auto Bdi<T>::operator==(const Bdi& other) -> bool
{
    return pointer == other.pointer;
}

template <typename T>
auto Bdi<T>::operator!=(const Bdi& other) -> bool
{
    return pointer != other.pointer;
}

template <typename T>
auto Bdi<T>::swap(Bdi& rhs) -> void
{
    std::swap(pointer, rhs.pointer);
}

template <typename T>
class Tree {
    /*! BSTree class*/
    Node<T>* root;
    
    auto clean(Node<T>*&) -> void;
    auto direct_print(std::ostream& out, Node<T>* node) const -> void;
    auto symmetric_print(std::ostream& out, Node<T>* node) const -> void;
    auto reverse_print(std::ostream& out, Node<T>* node) const -> void;
    friend auto print_() -> void;
    
public:
    enum class order { direct,
        symmetric,
        reverse };
    auto exists(T val) const -> bool;
    auto list(std::ostream& out, order ord) const -> void;
    auto insert(T val) -> void; // warning: trows stuff!
    auto remove(T val) -> void; // warning: trows stuff!
    auto print() -> void
    {
        print_(0, root);
    }
    auto empty() -> bool
    {
        return (root == nullptr) ? true : false;
    }
    auto save(std::string& filename) -> bool;
    auto load(std::string& filename) -> bool;
    auto friend operator<<(std::ostream& stream, const Tree<T>& tree) -> std::ostream &
    {
        return tree.list(stream, Tree<T>::order::direct);
    };
    auto swap(Tree<T>& tree) -> void
    {
        std::swap(root, tree.root);
    }
    auto operator=(const Tree<T>& tree) -> Tree<T> &
    {
        this->clean(root);
        Tree tmp{ tree };
        this->swap(tmp);
        return *this;
    }
    
    Tree()
    : root{ nullptr }
    {
    }
    Tree(std::initializer_list<T> list_)
    : Tree{}
    {
        //root = nullptr;
        for (auto& item : list_)
            this->insert(item);
            }
    Tree(const Tree<T>& tree)
    {
        std::string str;
        std::stringstream out(str);
        out << tree;
        T value;
        while (out) {
            out >> value;
            this->insert(value);
        }
    }
    ~Tree() { clean(root); }
    
    //auto remove_root(Node*&root, const int &value) ->void;
    auto begin() -> Bdi<T>
    {
        return Node<T>::min( root );
    }
    
    auto end() -> Bdi<T>
    {
        return nullptr;
    }
    
    auto rbegin() -> Bdi<T>
    {
        return Node<T>::max( root );
    }
    
    auto rend() -> Bdi<T>
    {
        return nullptr;
    }
};
template <typename T>
auto Tree<T>::exists(T val) const -> bool
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
    /*Node* working = root;
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
     return true;*/
}
template <typename T>
auto Tree<T>::clean(Node<T>*& node) -> void
{
    //use reverse met.
    if (node != nullptr) {
        clean(node->left);
        clean(node->right);
        delete node;
    }
    node = nullptr;
}
template <typename T>
auto Tree<T>::direct_print(std::ostream& out, Node<T>* node) const -> void
{
    if (node == nullptr)
        return;
    out << node->data << ' ';
    direct_print(out, node->left);
    direct_print(out, node->right);
    }
    template <typename T>
    auto Tree<T>::symmetric_print(std::ostream& out, Node<T>* node) const -> void
    {
        if (node == nullptr)
            return;
        symmetric_print(out, node->left);
        out << node->data << ' ';
        symmetric_print(out, node->right);
    }
    template <typename T>
    auto Tree<T>::reverse_print(std::ostream& out, Node<T>* node) const -> void
    {
        if (node == nullptr)
            return;
        direct_print(out, node->left);
        direct_print(out, node->right);
        out << node->data << ' ';
    }
    template <typename T>
    auto Tree<T>::list(std::ostream& out, order ord) const -> void
    {
        switch (ord) {
            case order::direct:
                direct_print(out, root);
                break;
            case order::symmetric:
                symmetric_print(out, root);
                break;
            case order::reverse:
                reverse_print(out, root);
                break;
        };
    }
    /*
     auto direct_print(const Tree *) ->void{
     
     }
     auto symmetric_print(const Tree *) ->void{
     
     }
     auto reverse_print(const Tree *) ->void{
     
     }*/
    template <typename T>
    auto print_(int depth, Node<T>* node) -> void
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
    
    /*auto Tree::return_root() -> Node * {
     return (root);
     }*/
    template <typename T>
    auto Tree<T>::insert(T val) -> void
    {
        if (root == nullptr) { // empty tree -> add root
            root = new Node<T>{ val };
            root->parent = nullptr;
            return;
        }
        // only if tree if not empty:
        
        if (exists(val))
            throw logic_error("уже есть"); // there should be only one branch/leaf with any value
        Node<T>* working = root;
        while (working != nullptr) {
            if (working->data > val) {
                if (working->left == nullptr) {
                    working->left = new Node<T>{ val };
                    working->left->parent = working;
                    break;
                }
                working = working->left;
            }
            else {
                
                if (working->right == nullptr) {
                    working->right = new Node<T>{ val };
                    working->right->parent = working;
                    break;
                }
                working = working->right;
            }
        }
    }
    /*
     while (working != nullptr) {
     if (working->data == val)
     throw logic_error("уже есть"); // there should be only one branch/leaf with any value
     if (working->data > val) {
     parental = working;
     working = working->left;
     working->parent = parental;
     }
     else {
     parental = working;
     working = working->right;
     working->parent = parental;
     }
     //exit if leaf/branch allready exists or found parental node for new node (working== nullptr)
     }
     if (working->parent->data < val)
     working->parent->right = new Node<T>{ val };
     else
     working->parent->left = new Node<T>{ val };
     return;
     }*/
    template <typename T>
    auto print_to(Node<T>* node, ofstream& f) -> void
    {
        if (node == nullptr)
            return;
        f << node->data << ' ';
        print_to(node->left, f);
        print_to(node->right, f);
    }
    template <typename T>
    auto Tree<T>::save(std::string& filename) -> bool
    {
        /*
         int access(const char *path, int amode);
         amode :
         F_OK - существование
         R_OK,
         W_OK,
         X_OK
         */
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
    template <typename T>
    auto Tree<T>::load(std::string& filename) -> bool
    {
        //if (!(access(filename.c_str(), F_OK))) {
        //  throw logic_error("файла нет");
        //}
        //if (!(access(filename.c_str(), R_OK)))
        //    throw logic_error(" нет прав на запись");
        if (!(access(filename.c_str(), F_OK))) {
            throw logic_error("Файл с заданным путем не существует");
        }
        std::ifstream fin(filename.c_str());
        int value;
        fin >> value;
        
        if (!fin)
            return false;
        this->clean(root);
        while (fin) {
            this->insert(value);
            fin >> value;
        }
        fin.close();
        return true;
    }
    template <typename T>
    auto Tree<T>::remove(T val) -> void
    {
        if (!exists(val))
            throw logic_error("такого значения найдено не было");
        Node<T>* working_parent = nullptr;
        Node<T>* working = root;
        Node<T>* pruned = nullptr;
        
        while (working->data != val) {
            working_parent = working;
            if (val > working->data)
                working = working->right;
            else
                working = working->left;
        } //after this loop i would have val in form of working->data == val
        if (!(working->left) || !(working->right)) {
            Node<T>* needed_child = nullptr;
            if (working->right)
                needed_child = working->right;
            else if (working->left)
                needed_child = working->left;
            if (!(working_parent))
                root = needed_child; //(!(working->left) && !(working->right))
            else if (working_parent->right == working)
                working_parent->right = needed_child;
            else
                working_parent->left = needed_child;
        }
        else {
            Node<T>* most_left = working->right;
            Node<T>* most_left_parent = working;
            while (most_left->left != nullptr) {
                most_left_parent = most_left;
                most_left = most_left->left;
            }
            most_left->parent = most_left_parent;
            working->data = most_left->data;
            pruned = most_left;
            if (most_left->parent->left == most_left)
                most_left->parent->left = nullptr;
            else
                most_left->parent->right = most_left->right;
        }
        delete pruned;
        pruned = nullptr;
    }
