/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:19:38 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/04 16:23:16 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    //@OK Test
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "Exception circumstance not found" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    try {
        // if everything is okay go next, if not go catch block.
        Bureaucrat a;
        Bureaucrat b("Josh", 149);
        Bureaucrat c = Bureaucrat("Bro", 2);
        
        b.increment();
        c.decrement();
        std::cout << a << '\n';
        std::cout << b << '\n';
        std::cout << c << '\n';
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << RED << e.what() << DEFAULT <<'\n';
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << RED << e.what() << DEFAULT << '\n';
    }
    std::cout << std::setfill('-') << std::setw(73) << '\n';

    //@KO Test
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "Exception circumstance found" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    try {
        // if everything is okay go next, if not go catch block.
        Bureaucrat c = Bureaucrat("Bro", 150);
        
        c.decrement();
        std::cout << c << '\n';
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << RED << e.what() << DEFAULT <<'\n';
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << RED << e.what() << DEFAULT << '\n';
    }
    std::cout << std::setfill('-') << std::setw(73) << '\n';
}