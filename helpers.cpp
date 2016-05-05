#include "Headers/helpers.h"
#include <stdio.h>
#include <iostream>


void print_vector(std::vector<uint8_t> v) {
    for (size_t i = 0; i < v.size(); i++) {
        printf("%d, ", v[i]);
    } 
    puts("");
}
