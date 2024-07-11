#ifndef MAT_22_HH
#define MAT_22_HH

#include "mat.h"

namespace vl{
/*
    *   class mat2 - derived from mat, implements features specilized for
    *   2x2 matices only.
    */
    template<typename T = float>
    class mat22 : public mat<T, 2, 2> {
    public:
        mat22();
        mat22<T>& inv();
        inline T det();     
    };

    template<typename T>
    mat22<T>::mat22() : mat<T, 2, 2>() {}

    template<typename T>
    inline T mat22<T>::det() {
        return this->_data[0][0] * this->_data[1][1] - 
               this->_data[0][1] * this->_data[1][0];
    }

    template<typename T>
    mat22<T>& mat22<T>::inv() {
        T d = det();
        assert((d != static_cast<T>(0.0)) && "Matrix is singular, can not be inverted");
        std::swap(this->_data[0][0], this->_data[1][1]);
        this->_data[1][0] *= static_cast<T>(-1.0);
        this->_data[0][1] *= static_cast<T>(-1.0);
        *this /= d;
        return *this;
    }
}

#endif