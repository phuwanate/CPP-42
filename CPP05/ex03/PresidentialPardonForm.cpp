/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:48:54 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 12:38:09 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5), _target("Default") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("PresidentialPardonForm", 25, 5), _target(target){

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance): Form(instance), _target(instance._target){
    
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
        throw Form::NotbeSigned();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw Form::GradeTooHighExcecution();

    std::cout << CYAN << this->_target << " has been pardoned by Zaphod Beeblebrox. " << '\n' << DEFAULT;
}