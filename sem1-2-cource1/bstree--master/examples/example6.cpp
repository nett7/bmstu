
#include "BSTree.hpp"
#include <iostream>

int main(int argc, const char* argv[]) {
    Tree<int> a;
    setlocale(LC_ALL, "rus");
    //ввод через запятую задание не подразумевает
    if (argc > 2) { //args < 2 => список пуст
        // через пробел
        a.insert(atoi(argv[1]));
        for (int i = 2; i < argc; ++i) {
            a.insert(atoi(argv[i]));
        }
    }
    
    
    
    Bdi<int> it = a.rbegin();
    for (; it != a.rend(); --it) {
        std::cout << *it << " ";
    }
    std::cout << *it << " ";
}
