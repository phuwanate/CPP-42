#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

enum arg_type{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    LITERALS,
    NONE
};

bool isChar(std::string const &arg);
void checkType(std::string const &arg, arg_type &_type);
void typeCast(std::string &arg, arg_type &_type);

#endif