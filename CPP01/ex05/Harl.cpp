/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:43:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/25 13:01:19 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "\033[38;2;0;255;255m" << "[DUBUG] " << '\n';
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << '\n';
	std::cout << "I really do!";
	std::cout << '\n' << "\033[0m";
}

void	Harl::info(void)
{
	std::cout << "\033[32m" << "[INFO]" << '\n';
	std::cout << "I cannot believe adding extra bacon costs more money." << '\n';
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << '\n' << "\033[0m";
}

void	Harl::waring(void)
{
	std::cout << "\033[38;2;255;165;0m" << "[WANRING]" << '\n';
	std::cout << "I think I deserve to have some extra bacon for free." << '\n'; 
	std::cout << "I’ve been coming for years whereas you started working here since last month.";
	std::cout << '\n' << "\033[0m";
}

void	Harl::error(void)
{
	std::cout << "\033[31m" << "[ERROR]" << '\n';
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << '\n' << "\033[0m";
}

void	Harl::complain(std::string level)
{
	Harl::func_ptr	func_arr[4] = {&Harl::debug, &Harl::info, &Harl::waring, &Harl::error};
	std::string		str_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == str_arr[i])
		{
			(this->*func_arr[i])();
			return ;
		}
	}
	std::cout << "\033[31m" << "Unknown level: " << level << '\n' << "\033[0m";
}
