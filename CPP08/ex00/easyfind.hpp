#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <exception>
#include <algorithm>

#include <vector>
#include <list>
#include <deque>

template <typename T>
void easyfind(T const& container, int const val){

    if (std::find(container.begin(), container.end(), val) != container.end())
        std::cout << "Found: [" << val << "] in the container." << '\n';
    else
        std::cout << RED << "Notfound: [" << val << "] in the container." << DEFAULT << '\n';
}

#endif