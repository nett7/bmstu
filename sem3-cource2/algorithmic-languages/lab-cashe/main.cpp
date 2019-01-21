#include <iostream>
#include <ctime>

int main() {
   // std::cout << sizeof(int);
     clock_t  t_start; 
     clock_t  t_end; 
    float RESULTAT=0;
    for (int N = 4; N*1000 < 46080*1.5; N*=2) {
        int mas_size = N * 1000;
        int mas[mas_size];
        for (int index = 0; index < mas_size; mas[index] = index, index++);
        for (int index = 0, a = 0; index < mas_size; a = mas[index], index++);
        t_start = clock();
        for (int count = 0; count < 1000; count++ ) {
           for (int index = 0, a = 0; index < mas_size; a = mas[index], index++);
        }
        t_end= clock() - t_start;
        RESULTAT = (float)t_end/CLOCKS_PER_SEC;
        std::cout << N << "  " << RESULTAT<< std::endl;
    }
    
}
