#include <iostream>
#include "mat.h"

int main(){
    //ds2::vec<int, 2> sa;
    /*ds2::vec2f sa;
    ds2::vec2f sa2;
    sa[0] = 2.1;
    sa[1] = 1.6;
    sa2[0] = 13; 

    ds2::vec2f sa3;
    sa3 = sa * 2.5;
    //sa += sa2;

    std::cout << sa3[0] << "\n\n";

    ds2::vec2f sa5(2,5);
    ds2::vec2f sa6(1,4);
    std::cout << (sa5 + sa6) / 2.00 << " " << (sa5 + sa6).length();*/

    ds2::vec2<float> ss(1,5);
    //ss[0] = 12;
    //ss[1] = 12;
    std::cout << ss.x << " " << ss.y;
}