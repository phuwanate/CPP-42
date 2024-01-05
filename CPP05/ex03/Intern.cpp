/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:46 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 11:33:44 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){

    std::cout << "Intern created." << '\n';
}
Intern::Intern(Intern const &instance){

    if (this != &instance)
        *this = instance;
    std::cout << "Intern coppied." << '\n';
}

Intern::~Intern(void){
    
    std::cout << "Intern destroyed." << '\n';
}

Intern	&Intern::operator=(Intern const &instance){

    (void)instance;
    return *this;
}

Form	*Intern::makeForm(std::string name, std::string target){

    std::string formName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    std::size_t index = -1;
    Form   *ptrForm = nullptr;
    
    for (std::size_t i=0; i < 3; i++)
    {
        if (name == formName[i])
        {
            index = i;
            break ;
        }
    }

    switch (index)
    {
        case 0:
                ptrForm = new ShrubberyCreationForm(target);
                break;
        case 1:
                ptrForm = new RobotomyRequestForm(target);
                break;
        case 2:
                ptrForm = new RobotomyRequestForm(target);
                break;
        default:
                std::cout << RED << "There is no " << name << " form." << DEFAULT << '\n';
                return nullptr;
    }
    std::cout << GREEN << "Intern creates " << name << "form." << '\n' << DEFAULT;
    return ptrForm;     
}