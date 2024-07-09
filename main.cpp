#include <iostream>
#include "mat.h"

int main(){
    //ds2::vec<int, 2> sa;
    ds2::vec2f sa;
    ds2::vec2f sa2;
    sa[0] = 10;
    sa2[0] = 123; 

    ds2::vec2f sa3;
    sa3 = sa + sa2;

    std::cout << sa3[0];
}