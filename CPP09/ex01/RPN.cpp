#include "RPN.hpp"

RPN::RPN(void): _Stack(), _res(0){ }

RPN::~RPN(void){ }

RPN::RPN(RPN const& inst): _Stack(){

    *this = inst;
}

RPN &RPN::operator=(RPN const& inst){

    if (this != &inst){
        this->_Stack = inst._Stack;
        this->_res = inst._res;
    }
    return *this;
}

bool RPN::__find_operator(int index, int x, int y){

    switch (index){
        case 0:
                _res = __add(x, y);
                break ;
        case 1:
                _res = __minus(x, y);
                break ;
        case 2:
                _res = __multiply(x, y);
                break ;
        case 3:
                _res = __divide(x, y);
                break ;
        default:
                return false;
    }
    return true;
}

void RPN::do_rpn(std::string arg){

    std::stringstream   stream(arg);
    int                 index;
    int                 first;
    int                 last;

    if (static_cast<const std::string>(arg) == ""){
        std::cout << RED << "Error: empty string." << '\n' << DEFAULT ;
        exit (EXIT_FAILURE);
    }
    try{
        while (stream >> arg){
            index = __is_ops(arg);
            if (index != -1){
                if (_Stack.size() < 2)
                    throw std::invalid_argument("Error: in stack must have at least 2 numbers before an operator.");
                first = _Stack.top();
                _Stack.pop();
                last = _Stack.top();
                _Stack.pop();
                if (__find_operator(index, last, first) == true){
                    if (_res < std::numeric_limits<int>::lowest() || _res > std::numeric_limits<int>::max())
                        throw std::overflow_error("Error: Operation is overflow.");
                    _Stack.push(_res);
                }
            }
            else
                _Stack.push(__ft_to_number<int>(__check_digit(arg)));
        }
        if (_Stack.size() != 1)
            throw std::invalid_argument("Error: too many numbers...");
        std::cout << _Stack.top() << '\n';
    }catch(std::exception &e){
        std::cout << RED << e.what() << '\n' << DEFAULT;
    }
}

std::string RPN::__check_digit(std::string const& arg){

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

std::size_t RPN::__is_ops(std::string const& arg){

    std::string ops[] = {"+", "-", "*", "/"};

    for (std::size_t i = 0; i < 4; i++){

        if (arg == ops[i])
            return i;
    }
    return -1;
}

template <typename T>
T RPN::__ft_to_number(std::string const& str){

    std::stringstream   stream(str);
    T tmp;

    stream >> tmp;
    if (tmp > 9 || tmp < 0)
        throw std::invalid_argument("Error: the numbers should be 0 - 9");
    return (tmp);
}