#ifndef RPN_HPP
# define RPN_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <limits>

class RPN{
	public:
								RPN(void);
								~RPN(void);
								RPN(RPN const& inst);
								RPN &operator=(RPN const& inst);
		void                    do_rpn(std::string arg);

	private:
			std::stack<int>     	_Stack;
			int                 	_res;

			std::plus<int>          __add;
			std::minus<int>         __minus;
			std::multiplies<int>    __multiply;
			std::divides<int>       __divide;

			std::size_t		__is_ops(std::string const& arg);
			std::string		__check_digit(std::string const& arg);

			bool            __find_operator(int index, int x, int y);
			
			//Convert string to numeric.
			template <typename T>
			T               __ft_to_number(std::string const& str);
};

#endif