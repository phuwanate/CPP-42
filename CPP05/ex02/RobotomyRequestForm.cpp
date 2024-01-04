/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:16:35 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 00:15:31 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("Default") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target){

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance): AForm(instance), _target(instance._target){
    
}

RobotomyRequestForm::~RobotomyRequestForm(void){

    std::cout << "RobotomyRequestForm destroyed." << '\n';
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &instance){

    if (this != &instance)
        this->_target = instance._target;
    return (*this);
}

void		    RobotomyRequestForm::execute(Bureaucrat const & executor) const{

    if (this->getFormStatus() == false)
        throw AForm::NotbeSigned();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowExcecution();

    static int i;
    std::cout << "Vvvvvvvvvv... BBZZZ ... vvvvvvvvvv" << '\n';
    if (i % 2 == 0)
        std::cout << GREEN << this->_target << " has been robotomized successfully!" << '\n' << '\n';
    else
        std::cout << RED << "Robotomy failed " << '\n' << '\n';
    std::cout << DEFAULT;
    i++;
}
