/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:19:38 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 00:13:34 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    ShrubberyCreationForm   form1("home");
    RobotomyRequestForm     form2("Robro");
    PresidentialPardonForm  form3("William");
    Bureaucrat              Josh("Josh", 1);

    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "ShrubberyCreationForm" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    Josh.signForm(form1);
    Josh.executeForm(form1);
    std::cout << std::setfill('-') << std::setw(73) << '\n';

    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "RobotomyRequestForm" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    Josh.signForm(form2);
    for (int i = 0; i < 4; i++)
        Josh.executeForm(form2);
    std::cout << std::setfill('-') << std::setw(73) << '\n';

    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "PresidentialPardonForm" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    Josh.signForm(form3);
    Josh.executeForm(form3);
    std::cout << std::setfill('-') << std::setw(73) << '\n';
}