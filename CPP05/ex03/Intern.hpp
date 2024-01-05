#ifndef INTERN_HPP
# define INTERN_HPP

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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
					Intern(void);
					Intern(Intern const &instance);
					~Intern(void);
			Intern	&operator=(Intern const &instance);
			Form	*makeForm(std::string name, std::string target);
};

#endif