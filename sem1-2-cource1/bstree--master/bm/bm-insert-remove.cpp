
#include <iostream>
#include <locale>
#include <ctime>
#include <cmath>
#include "BSTree.hpp"

int main() {
    setlocale(LC_ALL, "RUS");
    clock_t  t_start;
    clock_t  t_end;
    Tree  tree;
    for (size_t exp = 1; exp < 9;  exp ++ ) {
        int value;
        std::cout<<"Adding:"<<std::endl;
        t_start = clock();
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand()%100;
            try{
            tree.insert(value);
        }catch (logic_error e) {
            //cout << e.what() << endl;
            //return;
        }
        }
        t_end= clock() - t_start;
        std::cout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
        std::cout<<"Removing:"<<std::endl;
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            try{
            tree.remove(value);
            }catch (logic_error e) {
                //cout << e.what() << endl;
                //return;
            }

        }
        t_end= clock() - t_start;
        std::cout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
    }
}
