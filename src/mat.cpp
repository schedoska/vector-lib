#include "mat.h"






/*
 * Overloaded iostream function allowing for displaying content of matrix
*/
/*template<typename T, size_t H, size_t W>
std::ostream& operator<<(std::ostream& os, ml::mat<T, H, W>& m){
    for (size_t i = 0; i < H; ++i){
        for (size_t j = 0; j < W; ++j){
            os << m.at(i, j) << ", ";
        }
        os << "\n";
    }
    return os;
}*/

//template class ml::mat<float, 2, 1>;
//template class ml::mat<float>;
//template std::ostream& operator<<(std::ostream& os, ml::mat<float>& m);