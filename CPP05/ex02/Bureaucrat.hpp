#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
			std::string const	_name;
			int					_grade;
	public:
								Bureaucrat(void);
								Bureaucrat(std::string const name, int const grade);
								Bureaucrat(Bureaucrat const &instance);
								~Bureaucrat(void);
			Bureaucrat			&operator=(Bureaucrat const &instance);
			
			//Getters for attributes
			std::string			getName(void) const;
			int					getGrade(void) const;
			
			//Special own functions
			void				increment(void);
			void				decrement(void);
			void				signForm(AForm &instance);
			void				executeForm(AForm const & form);

			//Exception Class
			class GradeTooHighException : public std::exception
			{
				public:
						virtual const char* what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
						virtual const char* what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &instance);

#endif