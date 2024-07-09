#ifndef MAT_HH
#define MAT_HH 

#include <cstddef>
#include <iostream>
#include <array>

namespace ds2
{
    template<typename T, std::size_t N>
    class vec{
    public:
        vec();
        T& operator[](std::size_t i);
        const T& operator[](std::size_t i) const;
        vec<T, N> operator+(const vec<T, N>& v);

    private:
        std::array<T, N> _data;
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
    vec<T, N> vec<T, N>::operator+(const vec<T, N>& v) {
        vec<T, N> out;
        for(std::size_t i = 0; i < N; ++i) {
            out._data[i] = _data[i] + v._data[i];
        }
        return out;
    }

    using vec2f = vec<float, 2>;
}






#endif