/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:43:12 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/25 12:48:34 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    std::string line;
    Harl        harl;

    if (ac != 2)
    {
       std::cout << "\033[31m" << "The program should takes one parameters." << '\n';
       return (EXIT_FAILURE);
    }
    line = (std::string) av[1];
    harl.complain(line);
    return (EXIT_SUCCESS);
}