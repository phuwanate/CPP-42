#ifndef AFORM_HPP
# define AFORM_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
            std::string const   _name;
            bool                _formStatus;
            int const           _signedGrade;
            int const           _executeGrade;
    public:
					            AForm(void);
								AForm(std::string const name, int const gradeSigned,int const gradeExecute);
								AForm(AForm const &instance);
								~AForm(void);
			AForm				&operator=(AForm const &instance);
			//Getters for attributes
			std::string			getName(void) const;
			bool				getFormStatus(void) const;
			int					getSignedGrade(void) const;
			int					getExecuteGrade(void) const;
			virtual void		execute(Bureaucrat const & executor) const =0;

			//Special own function
			void				beSigned(Bureaucrat const &instance);
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
			class NotbeSigned : public std::exception
			{
				public:
						virtual const char* what() const throw();
			};
			class GradeTooHighExcecution : public std::exception
			{
				public:
						virtual const char* what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &o, AForm const &instance);



#endif