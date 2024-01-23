#include "BitcoinExchange.hpp"

int main(int ac, char **av){

    try{
        if (ac != 2)
            throw std::invalid_argument("Error: invalid arguments.");
        BitcoinExchange bitcoin_rate;
        bitcoin_rate.trade(av[1]);
    }catch (std::exception &e){
        std::cout << RED << e.what() << '\n' << DEFAULT;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}