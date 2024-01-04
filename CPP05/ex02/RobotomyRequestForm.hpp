#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class RobotomyRequestForm: public AForm{

    private:
            std::string             _target;
    public:
					                RobotomyRequestForm(void);
								    RobotomyRequestForm(std::string const &target);
								    RobotomyRequestForm(RobotomyRequestForm const &instance);
								    ~RobotomyRequestForm(void);
			RobotomyRequestForm	    &operator=(RobotomyRequestForm const &instance);

			void		    		execute(Bureaucrat const & executor) const;
};



#endif