
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
    std::cout << *it << " "<<endl;
    
    for (; it !=a.rbegin(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << *it << " "<<endl<<"###"<<endl;
    Bdi<int> it2 = it;
    for (; it2 != a.rend(); --it2) {
        std::cout << *it2 << " ";
    }
    std::cout << *it2 << " "<<endl;
    
    for (; it2 !=a.rbegin(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << *it2 << " ";
}
