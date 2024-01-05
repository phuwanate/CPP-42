/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:19:38 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/05 12:28:31 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    //@OK Test
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << GREEN << "OK Test" << '\n' << DEFAULT;
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    try {
        // if everything is okay go next, if not go catch block.
        Bureaucrat  Josh("Josh", 1);
        Form        paper("Budget Disbursement", 4, 1);

        std::cout << paper << '\n';
        Josh.signForm(paper);
    } catch (std::exception &e){
        std::cerr << RED << e.what() << DEFAULT << '\n';
    }
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    
    //@KO in beSigned() Test
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << GREEN << "KO Test" << '\n' << DEFAULT;
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    try {
        // if everything is okay go next, if not go catch block.
        Bureaucrat  Josh("Josh", 150);
        Form        paper("Budget Disbursement", 1, 1);
        
        std::cout << paper << '\n';
        Josh.signForm(paper);
    } catch (std::exception &e){
        std::cerr << RED << e.what() << DEFAULT << '\n';
    }
    std::cout << std::setfill('-') << std::setw(73) << '\n';

}