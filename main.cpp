#include <iostream>
#include "vec.h"
#include "mat.h"

int main(){
    ds2::vec<float, 2> k1;
    ds2::mat<float, 2, 2> k2;
    k2(1,1) = 3;
    ds2::mat<float, 4, 4> kk2;

    ds2::mat2<float> k3;
    k3(0,0) = 2;
    k3(1,1) = 4;


    std::cout << k2*k3;
}