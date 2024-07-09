#include <iostream>
#include "mat.h"

int main(){
    ds2::vec2f v1(2,6);
    ds2::vec2f v2(5,11);
    v1 += v2;

    std::cout << v1.norm() << " " << v1.len() << " " << v2;
}