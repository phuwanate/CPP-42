/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:17:36 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/08 15:51:23 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **arg)
{
    if (ac != 2)
    {
        std::cout << RED << "Error the program should takes 1 argument..." << '\n';
        return EXIT_FAILURE;
    }
    if (ScalarConverter::convert(arg[1]) == false)
    {
        std::cout << RED << "Error: Unknow Type..." << '\n' << DEFAULT;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}