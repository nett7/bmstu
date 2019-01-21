// Copyright 2018 ROSHCHIN Igor mosgreyday@gmail.com
#ifndef INCLUDE_BYPASS_HPP_
#define INCLUDE_BYPASS_HPP_

#include <stdlib.h>
#include <cstdint>
#include <iostream>

void dir_bypass(int*arr, int64_t arr_size) {
    for (int index = 0, a = 0; index < arr_size;
        a = arr[index], index++)
    {}
}
void rev_bypass(int*arr,  int64_t arr_size) {
    for (int index = arr_size, a = 0;
         index > 0; a = arr[index], index--)
    {}
}
void rnd_bypass(int*arr, int64_t arr_size) {
  // unsigned int seed_ = 300899;
  // unsigned int * seed = &seed_;
    for (int index = 0, a = 0;
    index < arr_size;
    a = arr[rand()%arr_size], index++)
    {}
}
#endif  // INCLUDE_BYPASS_HPP_
