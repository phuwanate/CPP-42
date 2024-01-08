#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <exception>

class ScalarConverter{

    private:
                            ScalarConverter(void);
    public:
                            ScalarConverter(ScalarConverter const &inst);
                            ~ScalarConverter(void);
            ScalarConverter &operator=(ScalarConverter const &inst);           
            
            static bool    convert(std::string arg);
};

#endif