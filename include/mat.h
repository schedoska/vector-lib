#ifndef MAT_HH
#define MAT_HH

#include <cstddef>
#include <iostream>
#include <array>
#include <cmath>
#include <type_traits>
#include <cassert>

template<typename T, std::size_t N>
class vec;

namespace ds2
{
    template<typename T, std::size_t H, std::size_t W>
    class mat{
    public:
        mat();
        T& operator() (std::size_t r, std::size_t c);
        const T& operator() (std::size_t r, std::size_t c) const;
        mat<T, H, W> operator+(const mat<T, H, W>& m) const;
        mat<T, H, W> operator-(const mat<T, H, W>& m) const;
        const mat<T, H, W>& operator+=(const mat<T, H, W>& m);
        const mat<T, H, W>& operator-=(const mat<T, H, W>& m);

        template<typename S> 
        mat<T, H, W> operator*(const S& val) const;
        template<typename S> 
        mat<T, H, W> operator/(const S& val) const;
        template<typename S> 
        const mat<T, H, W>& operator*=(const S& val);
        template<typename S> 
        const mat<T, H, W>& operator/=(const S& val);

        template<typename _T, std::size_t _H, std::size_t _W>
        mat<T, H, W> operator*(const mat<_T, _H, _W>& m) const;

        template<typename _T, std::size_t _N>
        vec<_T, _N> operator*(const vec<_T, _N>& v) const;

        // TO DO:
        mat<T, H, W>& inv() { return *this; }

    protected:
        std::array<std::array<T, W>, H> _data;
    };

    template<typename T, std::size_t H, std::size_t W>
    mat<T, H, W>::mat() {
        for(auto& r : _data) r.fill(static_cast<T>(0.0));
    }

    template<typename T, std::size_t H, std::size_t W>
    T& mat<T, H, W>::operator() (std::size_t r, std::size_t c) {
        return _data[r][c];
    }

    template<typename T, std::size_t H, std::size_t W>
    const T& mat<T, H, W>::operator() (std::size_t r, std::size_t c) const {
        return _data[r][c];
    }

    template<typename T, std::size_t H, std::size_t W>
    mat<T, H, W> mat<T, H, W>::operator+(const mat<T, H, W>& m) const {
        mat<T, H, W> om;
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                om(i,j) = m(i,j) + (*this)(i,j);
            }
        }
        return om;
    }

    template<typename T, std::size_t H, std::size_t W>
    mat<T, H, W> mat<T, H, W>::operator-(const mat<T, H, W>& m) const {
        mat<T, H, W> om;
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                om(i,j) = (*this)(i,j) - m(i,j);
            }
        }
        return om;
    }

    template<typename T, std::size_t H, std::size_t W>
    const mat<T, H, W>& mat<T, H, W>::operator+=(const mat<T, H, W>& m) {
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                (*this)(i,j) += m(i,j);
            }
        }
        return *this;
    }

    template<typename T, std::size_t H, std::size_t W>
    const mat<T, H, W>& mat<T, H, W>::operator-=(const mat<T, H, W>& m) {
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                (*this)(i,j) -= m(i,j);
            }
        }
        return *this;
    }

    template<typename T, std::size_t H, std::size_t W>
    template<typename S> 
    mat<T, H, W> mat<T, H, W>::operator*(const S& val) const {
        mat<T, H, W> m = *this;
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                m(i,j) *= val;
            }
        }
        return m;
    };

    template<typename T, std::size_t H, std::size_t W>
    template<typename S> 
    mat<T, H, W> mat<T, H, W>::operator/(const S& val) const {
        mat<T, H, W> m = *this;
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                m(i,j) /= val;
            }
        }
        return m;
    };

    template<typename T, std::size_t H, std::size_t W>
    template<typename S> 
    const mat<T, H, W>& mat<T, H, W>::operator*=(const S& val) {
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                _data[i][j] *= val;
            }
        }
        return *this;
    }

    template<typename T, std::size_t H, std::size_t W>
    template<typename S> 
    const mat<T, H, W>& mat<T, H, W>::operator/=(const S& val) {
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                _data[i][j] /= val;
            }
        }
        return *this;
    }

    template<typename T, std::size_t H, std::size_t W>
    template<typename _T, std::size_t _H, std::size_t _W>
    mat<T, H, W> mat<T, H, W>::operator*(const mat<_T, _H, _W>& m) const {
        static_assert(W == _H, "Matrices can not be multiplied");
    }

    template<typename T, std::size_t H, std::size_t W>
    template<typename _T, std::size_t _N>
    vec<_T, _N> mat<T, H, W>::operator*(const vec<_T, _N>& v) const {
        static_assert(W == _N, "Matrix width does not equal to vector length");
        vec<_T, _N> r_v;
        for(std::size_t i = 0; i < H; i++){
            for(std::size_t j = 0; j < W; j++){
                r_v(i) += (*this)(i,j) * v(i);
            }
        }
        return r_v;
    }

    /*
    *   class mat2 - derived from mat, implements features specilized for
    *   2x2 matices only.
    */
    template<typename T>
    class mat2 : public mat<T, 2, 2> {
    public:
        mat2();
        mat2<T>& inv();
        inline T det();

        template<typename _T, std::size_t _H, std::size_t _W>
        mat<T, H, W> operator*(const mat<_T, _H, _W>& m) const;

        
    };

    template<typename T>
    mat2<T>::mat2() : mat<T, 2, 2>() {}

    template<typename T>
    inline T mat2<T>::det() {
        return this->_data[0][0] * this->_data[1][1] - 
               this->_data[0][1] * this->_data[1][0];
    }

    template<typename T>
    mat2<T>& mat2<T>::inv() {
        T d = det();
        assert((d != static_cast<T>(0.0)) && "Matrix is singular, can not be inverted");
        std::swap(this->_data[0][0], this->_data[1][1]);
        this->_data[1][0] *= static_cast<T>(-1.0);
        this->_data[0][1] *= static_cast<T>(-1.0);
        *this /= d;
        return *this;
    }
}

template<typename T, std::size_t H, std::size_t W>
std::ostream& operator <<(std::ostream& out, const ds2::mat<T, H, W>& m) {
    std::cout << "[";
    for(std::size_t i = 0; i < H; i++){
        for(std::size_t j = 0; j < W; j++){
            std::cout << m(i,j);
            if(j < W - 1) std::cout << ", ";
        }
        if(i < H - 1) std::cout << "; ";
    }
    std::cout << "]";
    return out;
};

#endif