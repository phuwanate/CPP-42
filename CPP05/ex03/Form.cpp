/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:08:30 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 00:02:28 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("Default"), _formStatus(false), _signedGrade(4), _executeGrade(0){

	if (_signedGrade < 1 || _executeGrade < 1) 
		throw Form::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Default called" << '\n';
}

Form::Form(std::string const name, int const gradeSigned,int const gradeExecute):\
_name(name), _formStatus(false), _signedGrade(gradeSigned), _executeGrade(gradeExecute){
	
	if (_signedGrade < 1 || _executeGrade < 1) 
		throw Form::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &instance): _name(instance._name), _formStatus(instance._formStatus),\
_signedGrade(instance._signedGrade), _executeGrade(instance._executeGrade){

	std::cout << "Copy constructor called" << '\n';    
}

Form::~Form(void){

	std::cout << "Form, " << this->_name << " destroyed." << '\n';
}

Form	&Form::operator=(Form const &instance){
	
	if (this != &instance)
		this->_formStatus = instance._formStatus;
	return *this;
}

std::string		Form::getName(void) const{

	return (this->_name);
}

bool    Form::getFormStatus(void) const{

	return (this->_formStatus);
}

int     Form::getSignedGrade(void) const{

	return (this->_signedGrade);
}


int     Form::getExecuteGrade(void) const{

	return (this->_executeGrade);
}

void	Form::beSigned(Bureaucrat const &instance){
	
	if (instance.getGrade() > this->_signedGrade)
		throw Form::GradeTooLowException();
	this->_formStatus = true;
}

const char *Form::GradeTooHighException::what() const throw(){

	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw(){

	return "Grade is too low";
}

const char *Form::GradeTooHighExcecution::what() const throw(){

	return "grade is too high to execute.";
}

const char *Form::NotbeSigned::what() const throw(){

	return "the form not signed";
}

std::ostream	&operator<<(std::ostream &o, Form const &instance){

	o << "Form: " << '\n';
	o << "Name            : " << instance.getName() << '\n';
	o << "Form status     : " << instance.getFormStatus() << '\n';
	o << "Grade to Signed : " << instance.getSignedGrade() << '\n';
	o << "Grade to Execute: " << instance.getExecuteGrade() << '\n' << DEFAULT;
	return o;
}
