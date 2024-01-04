/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:48:54 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 00:13:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("Default") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target){

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance): AForm(instance), _target(instance._target){
    
}

PresidentialPardonForm::~PresidentialPardonForm(void){

    std::cout << "PresidentialPardonForm destroyed." << '\n';
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &instance){

    if (this != &instance)
        this->_target = instance._target;
    return (*this);
}

void		    PresidentialPardonForm::execute(Bureaucrat const & executor) const{

    if (this->getFormStatus() == false)
        throw AForm::NotbeSigned();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowExcecution();

    std::cout << CYAN << this->_target << " has been pardoned by Zaphod Beeblebrox. " << '\n' << DEFAULT;
}