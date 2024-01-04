/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:08:30 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 00:02:28 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("Default"), _formStatus(false), _signedGrade(4), _executeGrade(0){

	if (_signedGrade < 1 || _executeGrade < 1) 
		throw AForm::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Default called" << '\n';
}

AForm::AForm(std::string const name, int const gradeSigned,int const gradeExecute):\
_name(name), _formStatus(false), _signedGrade(gradeSigned), _executeGrade(gradeExecute){
	
	if (_signedGrade < 1 || _executeGrade < 1) 
		throw AForm::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &instance): _name(instance._name), _formStatus(instance._formStatus),\
_signedGrade(instance._signedGrade), _executeGrade(instance._executeGrade){

	std::cout << "Copy constructor called" << '\n';    
}

AForm::~AForm(void){

	std::cout << "AForm, " << this->_name << " destroyed." << '\n';
}

AForm	&AForm::operator=(AForm const &instance){
	
	if (this != &instance)
		this->_formStatus = instance._formStatus;
	return *this;
}

std::string		AForm::getName(void) const{

	return (this->_name);
}

bool    AForm::getFormStatus(void) const{

	return (this->_formStatus);
}

int     AForm::getSignedGrade(void) const{

	return (this->_signedGrade);
}


int     AForm::getExecuteGrade(void) const{

	return (this->_executeGrade);
}

void	AForm::beSigned(Bureaucrat const &instance){

	if (instance.getGrade() > this->_signedGrade)
		throw AForm::GradeTooLowException();
	this->_formStatus = true;
}

const char *AForm::GradeTooHighException::what() const throw(){

	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw(){

	return "Grade is too low";
}

const char *AForm::GradeTooHighExcecution::what() const throw(){

	return "Grade is too high to execute.";
}

const char *AForm::GradeTooLowExcecution::what() const throw(){

	return "Grade is too low to execute.";
}

const char *AForm::NotbeSigned::what() const throw(){

	return "the form not signed";
}

std::ostream	&operator<<(std::ostream &o, AForm const &instance){

	o << ORANGE << "AForm: " << '\n';
	o << "Name            : " << instance.getName() << '\n';
	o << "AForm status     : " << instance.getFormStatus() << '\n';
	o << "Grade to Signed : " << instance.getSignedGrade() << '\n';
	o << "Grade to Execute: " << instance.getExecuteGrade() << '\n' << DEFAULT;
	return o;
}
