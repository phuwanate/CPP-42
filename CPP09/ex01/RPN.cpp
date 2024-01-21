#include "RPN.hpp"

RPN::RPN(void){

    this->_func_arr[0] = &RPN::add;
    this->_func_arr[1] = &RPN::subtract;
    this->_func_arr[2] = &RPN::multiply;
    this->_func_arr[3] = &RPN::divide;
}

RPN::~RPN(void){ }

RPN::RPN(RPN const& inst) {

    *this = inst;
}

RPN &RPN::operator=(RPN const& inst){

    if (this != &inst)
        this->_Stack = inst._Stack;
    return *this;
}

void RPN::do_rpn(std::string arg){

    std::stringstream   stream(arg);
    int                 index;
    int                 first;
    int                 last;
    int                 res;

    try{
        while (stream >> arg){

            index = is_ops(arg);
            if (index != -1){
                if (this->_Stack.size() < 2)
                    throw std::invalid_argument("Error: in stack must have at least 2 numbers before an operator.");
                first = this->_Stack.top();
                this->_Stack.pop();
                last = this->_Stack.top();
                this->_Stack.pop();
                res = (this->*_func_arr[index])(last, first); 
                this->_Stack.push(res);
            }
            else
                this->_Stack.push(std::stoi(check_digit(arg)));
        }
        if (this->_Stack.size() != 1)
            throw std::invalid_argument("Error: too many numbers...");
        std::cout << this->_Stack.top() << '\n';
    }catch(std::exception &e){
        std::cout << e.what() << '\n';
    }
}

std::string RPN::check_digit(std::string const& arg){

    std::size_t i = 0;

    if (arg.length() == 0)
        throw std::invalid_argument("Error: empty input.");
    if (arg[0] == '+' || arg[0] == '-')
        i++;
    for(; i < arg.length(); i++)
    {
        if (std::isdigit(arg[i]) == 0)
            throw std::invalid_argument("Error: not a number.");  
    }
    return arg;
}

std::size_t RPN::is_ops(std::string const& arg){

    std::string ops[] = {"+", "-", "*", "/"};

    for (std::size_t i = 0; i < 4; i++){

        if (arg == ops[i])    
            return i;
    }
    return -1;
}

int RPN::add(int x, int y) { return (x + y); }

int RPN::subtract(int x, int y) { return (x - y); }

int RPN::multiply(int x, int y) { return (x * y); }

int RPN::divide(int x, int y) {
    
    if (y == 0)
        throw std::invalid_argument("Error: Floating point exception (Divide by zero error).");
    return ( x / y);
}