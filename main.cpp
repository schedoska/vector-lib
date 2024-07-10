#include <iostream>
#include "vec.h"
#include "mat.h"

int main(){
    ds2::vec2f v1(2,6);
    ds2::vec2f v2(5,11);
    v1 += v2;
    ds2::mat<float, 2, 2> m;
    m(0,1) = 2;
    m(1,0) = 2;

    std::cout << (m/2)*v1;
}