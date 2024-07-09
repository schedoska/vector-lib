#ifndef MAT_HH
#define MAT_HH 

#include <cstddef>
#include <iostream>
#include <array>
#include <cmath>

#define DOUBLE_PRECISION

namespace ds2
{
    #ifdef DOUBLE_PRECISION
    using _value = double;
    #endif

    template<typename T, std::size_t N>
    class vec{
    public:
        vec();
        T& operator[](std::size_t i);
        const T& operator[](std::size_t i) const;
        vec<T, N> operator+(const vec<T, N>& v) const;
        vec<T, N> operator-(const vec<T, N>& v) const;
        const vec<T, N>& operator+=(const vec<T, N>& v);
        const vec<T, N>& operator-=(const vec<T, N>& v);

        template<typename S> vec<T, N> operator*(const S& val) const;
        template<typename S> vec<T, N> operator/(const S& val) const;

        inline _value length() const;
        inline _value dot(const vec<T, N>& v) const;
        template<typename ... Args> vec(const T& e1, const Args& ... par);

    protected:
        std::array<T, N> _data;

        void push(std::size_t i);
        template<typename ... Args> void push(std::size_t i, const T& e1, const Args& ... par);
    };

    template<typename T, std::size_t N>
    vec<T, N>::vec() {
        _data.fill(0.0);
    }

    template<typename T, std::size_t N>
    const T& vec<T, N>::operator[](std::size_t i) const {
        return _data[i];
    }

    template<typename T, std::size_t N>
    T& vec<T, N>::operator[](std::size_t i) {
        return _data[i];
    }

    template<typename T, std::size_t N>
    vec<T, N> vec<T, N>::operator+(const vec<T, N>& v) const {
        vec<T, N> out;
        for(std::size_t i = 0; i < N; ++i) {
            out._data[i] = _data[i] + v._data[i];
        }
        return out;
    }

    template<typename T, std::size_t N>
    vec<T, N> vec<T, N>::operator-(const vec<T, N>& v) const {
        vec<T, N> out;
        for(std::size_t i = 0; i < N; ++i) {
            out._data[i] = _data[i] - v._data[i];
        }
        return out;
    }

    template<typename T, std::size_t N>
    const vec<T, N>& vec<T, N>::operator+=(const vec<T, N>& v) {
        for(std::size_t i = 0; i < N; ++i) {
            _data[i] += v._data[i];
        }
        return *this;
    }

    template<typename T, std::size_t N>
    const vec<T, N>& vec<T, N>::operator-=(const vec<T, N>& v) {
        for(std::size_t i = 0; i < N; ++i) {
            _data[i] -= v._data[i];
        }
        return *this;
    }

    template<typename T, std::size_t N>
    inline _value vec<T, N>::length() const {
        _value s = (_value)0.0;
        for(std::size_t i = 0; i < N; ++i) {
            s += std::pow(_data[i], 2);
        }
        return std::sqrt(s);
    }

    template<typename T, std::size_t N>
    inline _value vec<T, N>::dot(const vec<T, N>& v) const {
        _value s = (_value)0.0;
        for(std::size_t i = 0; i < N; ++i) {
            s += _data[i] * v._data[i];
        }
        return s;
    }

    template<typename T, std::size_t N>
    template<typename ... Args> 
    vec<T, N>::vec(const T& e1, const Args& ... arg) {
        push(0, e1, arg...);
    }

    template<typename T, std::size_t N>
    template<typename ... Args> 
    void vec<T, N>::push(std::size_t i, const T& e1, const Args& ... par) {
        //std::cout << i << " --: " << e1 << "\n";
        _data[i] = e1;
        push(++i, par...);
    }

    template<typename T, std::size_t N>
    void vec<T, N>::push(std::size_t i) {
        return; 
    }

    template<typename T, std::size_t N>
    template<typename S> 
    vec<T, N> vec<T, N>::operator*(const S& val) const {
        vec<T, N> o = *this;
        for(T& t : o._data) {
            t *= val;
        }
        return o;
    };

    template<typename T, std::size_t N>
    template<typename S> 
    vec<T, N> vec<T, N>::operator/(const S& val) const {
        vec<T, N> o = *this;
        for(T& t : o._data) {
            t /= val;
        }
        return o;
    };

    //using vec2f = vec<float, 2>;

    template<typename T>
    class vec2 : public vec<T, 2> {
    public:
        vec2();
        template<typename ... Args> vec2(const T& e1, const Args& ... par);
        T& x, y; 
    };

    template<typename T> 
    vec2<T>::vec2()
     : x(this->_data[0]), y(this->_data[1]) {}

    template<typename T>
    template<typename ... Args> 
    vec2<T>::vec2(const T& e1, const Args& ... arg)
     : vec<T, 2>(e1, arg...), x(this->_data[0]), y(this->_data[1]) {}



    //template class vec<int, 2>;
}

template<typename T, std::size_t N>
std::ostream& operator <<(std::ostream& out, const ds2::vec<T, N>& v) {
    std::cout << "[";
    for(std::size_t i = 0; i < N; ++i) {
        std::cout << v[i];
        if(i < N - 1) std::cout << ", ";
    }
    std::cout << "]";
    return out;
};






#endif