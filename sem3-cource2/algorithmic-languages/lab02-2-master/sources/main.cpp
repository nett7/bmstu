// Copyright 2018 ROSHCHIN Igor mosgreyday@gmail.com
//#include <chrono>
#include <stdlib.h>
#include <ctime>
#include <cstdint>
#include "bypass.hpp"

int main() {
    unsigned int seed_ = 300899;
    unsigned int * seed = &seed_;
    std::cout << "-------dir tests:-------" << std::endl;
    for (int N = 32; N <= 2048; N *= 2) {
        int64_t arr_size = N * 1024;
        int * arr = new int[arr_size];
        dir_bypass(arr, arr_size);
        //auto t_start = std::chrono::high_resolution_clock::now();
        clock_t t_start = clock();
        for (int count = 0; count < 1000; count++) {
          dir_bypass(arr, arr_size);
        }
        //auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << "test " << N<< "k "<<
        clock() - t_start
        //std::chrono::duration_cast<std::chrono::milliseconds>
        //(t_end - t_start).count()
        << std::endl;
    }
    std::cout << "-------rev tests:-------" << std::endl;
    for (int N = 32; N <= 2048; N *= 2) {
        int64_t arr_size = N * 1024;
        int * arr = new int[arr_size];
        dir_bypass(arr, arr_size);
        //auto t_start = std::chrono::high_resolution_clock::now();
        clock_t t_start = clock();
        for (int count = 0; count < 1000; count++) {
          rev_bypass(arr, arr_size);
        }
        //auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << "test " << N<< "k "<<
        //std::chrono::duration_cast<std::chrono::milliseconds>
        //(t_end - t_start).count()
        clock() - t_start
        << std::endl;
    }
    std::cout << "-------rnd tests:-------" << std::endl;
    for (int N = 32; N <= 2048; N *= 2) {
        int64_t arr_size = N * 1024;
        int * arr = new int[arr_size];
        dir_bypass(arr, arr_size);
        //auto t_start = std::chrono::high_resolution_clock::now();
        clock_t t_start = clock();
        for (int count = 0; count < 1000; count++) {
          rnd_bypass(arr, arr_size);
        }
        //auto t_end = std::chrono::high_resolution_clock::now();
        //auto t_start_sub = std::chrono::high_resolution_clock::now();
        for (int count = 0; count < 1000; count++) {
            for (int index = 0, a = 0; index < arr_size;
                 a = rand_r(seed) % arr_size, index++)
            {}
        }
        //auto t_end_sub = std::chrono::high_resolution_clock::now();
        //auto t_diff = std::chrono::duration_cast<std::chrono::milliseconds>
        //(t_end_sub - t_start_sub).count();
        //auto t_res = std::chrono::duration_cast<std::chrono::milliseconds>
        //(t_end - t_start).count();
        std::cout << "test " << N<< "k "<< clock() - t_start << std::endl;
    }
}
