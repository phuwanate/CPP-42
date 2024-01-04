/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:43:12 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/25 12:12:03 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    std::string line;
    Harl        harl;
    
    std::cout << "-> Harl...who always complains" << '\n';
    std::cout << "-> Choose one: DEBUG, INFO, WARNING, ERROR" << '\n';
    std::cout << "----------------------------------------------------" << '\n';
    std::cout << "-> Level you want Harl to complains: ";
    while(getline(std::cin, line))
    {
        if (line == "\0")
        {
            std::cout << "\033[31m" << "-> Don't leave the empty line, He needs to complain !!!";
            std::cout << '\n' << "\033[0m";
            std::cout << "-> Level you want Harl to complains: ";
            continue;
        }
        harl.complain(line);
        return (EXIT_SUCCESS);
    }
}