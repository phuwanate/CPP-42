#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <exception>

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#pragma once

template <typename T, std::size_t N>
std::size_t getSize(T (&)[N]) {
    return N;
}

template <typename T>
void call_arr(T *arr, std::size_t N){

    for (std::size_t i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

template <typename T>
void iter(T *arr, std::size_t N, void (* f)(T *, std::size_t)){
    
    if (static_cast<long>(N) <= 0) {
        std::cout << RED << "Error: size is not correct." << DEFAULT << '\n';
        return ;
    }
    f(arr, N);
}

#endif