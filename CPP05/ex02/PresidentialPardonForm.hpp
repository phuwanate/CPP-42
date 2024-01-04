#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm{

    private:
            std::string             _target;
    public:
					                PresidentialPardonForm(void);
								    PresidentialPardonForm(std::string const &target);
								    PresidentialPardonForm(PresidentialPardonForm const &instance);
								    ~PresidentialPardonForm(void);
			PresidentialPardonForm	&operator=(PresidentialPardonForm const &instance);

			void					execute(Bureaucrat const & executor) const;
};



#endif