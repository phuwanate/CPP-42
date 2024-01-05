#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form{

    private:
            std::string             _target;
    public:
					                ShrubberyCreationForm(void);
								    ShrubberyCreationForm(std::string const &target);
								    ShrubberyCreationForm(ShrubberyCreationForm const &instance);
								    ~ShrubberyCreationForm(void);
			ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &instance);

			void		    		execute(Bureaucrat const & executor) const;
};



#endif