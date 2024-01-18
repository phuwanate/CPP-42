#ifndef RPN_HPP
# define RPN_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <exception>

class RPN{
    public:
            RPN(void);
            ~RPN(void);
            RPN(RPN const& inst);
            RPN &operator=(RPN const& inst);

            int add(int x, int y);
            int subtract(int x, int y);
            int multiply(int x, int y);
            int divide(int x, int y);

            void        do_rpn(std::string &arg);
            int         is_ops(std::string &arg, std::string &ops);
            std::string check_digit(std::string const& arg);

    private:
            std::stack<int>     _Stack;
            
            typedef int (RPN::*func_ptr)(int, int);
            RPN::func_ptr   _func_arr[4];
};

#endif