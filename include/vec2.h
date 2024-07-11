#ifndef VEC_2_HH
#define VEC_2_HH

#include "vec.h"

namespace vl {
/*
    *   class vec2 - derived from vec, implements features specilized for
    *   2D vectors only.
    */
    template<typename T = float>
    class vec2 : public vec<T, 2> {
    public:
        vec2();
        vec2(const std::initializer_list<T>& l);
        template<typename ... Args> vec2(const T& e1, const Args& ... par);
        T& x, y; 
    };

    template<typename T> 
    vec2<T>::vec2() : 
        x(this->_data[0]), 
        y(this->_data[1]) {}

    template<typename T> 
    vec2<T>::vec2(const std::initializer_list<T>& l) :
        vec<T, 2>(l), 
        x(this->_data[0]), 
        y(this->_data[1]) {}

    template<typename T>
    template<typename ... Args> 
    vec2<T>::vec2(const T& e1, const Args& ... arg) : 
        vec<T, 2>(e1, arg...), 
        x(this->_data[0]), 
        y(this->_data[1]) {}

}

#endif