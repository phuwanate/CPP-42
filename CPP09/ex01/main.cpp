#include "RPN.hpp"

int main(int ac, char **av){

    RPN     rpn;

    if (ac != 2){
    
        std::cout << RED << "Error: invalid argument" << '\n' << DEFAULT;
        return EXIT_FAILURE;
    }
    rpn.do_rpn(av[1]);
    return EXIT_SUCCESS;
}