#include <iostream>

struct Node
{
  int data;
  Node * next;
};

class Flist
{
public:
  Node * first;
  void add(int a);
  int length();
  void print();
  Flist() : first(nullptr) {};
  Flist(Node* _f) : first(_f) {};
  ~Flist();
};

void Flist::add(int a)
{
  if (first == nullptr)
    {
        first = new Node{ a, nullptr };
        return;
    }
    Node* working = first;
    while (working->next != nullptr) {
        working = working->next;
    }
    working->next = new Node{ a, nullptr };
}

void Flist::print()
{
  if (first == nullptr){
    std::cout << "List is empty" <<std::endl;
    return;
  }
  std::cout << "List is not empty, here it is:" << std::endl;
  std::cout << "first ->";
  for (Node * temp = first; temp != nullptr; temp = temp->next){
    std::cout << " " << temp->data << " ->";
  }
  std::cout << " end!" <<std::endl;
}

int Flist::length(){
  if (first == nullptr) {return 0;}
  int i = 1;
  for (Node * temp = first; temp->next != nullptr; i++, temp=temp->next);
  return i;
}

Flist::~Flist()
{
  for (Node* temp = first; temp != nullptr; temp = temp->next)
    delete temp;
}

int main(){
  Flist a;
  a.print();
  // std::cout << a.length() << std::endl;
  a.add(1);
  // std::cout << a.length() << std::endl;
  a.print();
}
