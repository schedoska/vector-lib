#include <iostream>
#include "vec2.h"
#include "mat22.h"

int main(){
    vl::vec2<float> vec = {3,5};
    vl::vec<float, 2> vv = {7,2};

    std::cout << vv + vec;
}