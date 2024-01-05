/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:58:13 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 12:42:27 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(1){

    if (_grade < 1) 
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    // std::cout << "Default Constructor called" << '\n';
}

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name), _grade(grade){

    if (_grade < 1) 
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &instance): _name(instance._name), _grade(instance._grade){
    
    std::cout << "Copy constructor called" << '\n';
}
Bureaucrat::~Bureaucrat(void){

    std::cout << "Bureaucrat, " << this->_name << " destroyed." << '\n';
}

Bureaucrat      &Bureaucrat::operator=(Bureaucrat const &instance){

    if (this != &instance)
        _grade = instance._grade;
    return (*this);
}

std::string     Bureaucrat::getName(void) const{

    return _name;
}

int     Bureaucrat::getGrade(void) const{

    return _grade;
}

void				Bureaucrat::increment(void){

    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= 1;
}
void				Bureaucrat::decrement(void){

    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += 1;
}

void    Bureaucrat::signForm(Form &form){

    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << '\n';
    }catch (std::exception &e){
        std::cout << RED << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << '\n' << DEFAULT;
    }
}

void Bureaucrat::executeForm(Form const &form){

    try
    {
        std::cout << this->_name << " executed " << form.getName() << '\n' << DEFAULT;
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << RED << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << '\n' << DEFAULT;
    }
    
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    
    return "Grade is too high !";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    
    return "Grade is too low !";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &instance){

    o << GREEN << instance.getName() <<  ", grade " << instance.getGrade() << DEFAULT;
    return o;
}
