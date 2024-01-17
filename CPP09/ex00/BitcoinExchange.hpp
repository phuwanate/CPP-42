#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>


class BitcoinExchange{

    private:
            std::map<std::string, std::string>  _exchangeData;

    public:
            BitcoinExchange(void);
            ~BitcoinExchange(void);
            BitcoinExchange(BitcoinExchange const& inst);
            BitcoinExchange &operator=(BitcoinExchange const& inst);
            
            void            trade(std::string const& file_txt);
            std::string     trim_space(std::string const& str);

            void            find_year_range(std::map<std::string, int> &inst);

            //valid data checker.
            void            is_value_valid(std::string const& value);
            void            is_date_valid(std::string const& value);

            class InvalidFile: public std::exception{

                virtual const char* what() const throw();
            };
            class InvalidArgument: public std::exception{

                virtual const char* what() const throw();
            };
            class InvalidValue: public std::exception{

                virtual const char* what() const throw();
            };

};

#endif