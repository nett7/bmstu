struct Node{
int data;

Node * left;
Node * right;
Node(int val) :left(nullptr), right(nullptr){
data = val;
}

};

class Tree {
Node * root;
void clean(Node * & node) {
//use reverse met.
clean(node->left);
clean(node->right);
delete node; // delete only relese memory, but links stay untuched
node = nullptr;
}
void direct_print(Node * node){
cout « node->data;
print (Node -> left);
print (Node -> right);
}
public:

enum class order {direct, symmetric, reverse};

auto operatot =( Tree& tree) -> Tree&;
Tree() :root(nullptr);

auto list(order ord) {
swith (ord) {
case order::direct :
direct_print(root);
case order::symmetric;
//....


};
}
Tree (const Tree& tree);
bool incert(int val){

return False; // if element already exists
return True; // elsewise 
}
~Tree() {
// use one of recur met
clean(root);
}
bool remove (int val) {
return False; // if not found node with val value
return True; // elsewise + after removed
}
bool find(int val) 
{
return False;
}

}

int main() {
Tree tree;
tree.incert(4);
tree.incert(3);
tree.incert(2);

cout « tree.find(3);


Tree tree3;
tree3 = tree;
Tree tree2 = tree3;
Tree tree2(tree3)

}
