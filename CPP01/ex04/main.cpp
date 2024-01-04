/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:42:45 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/24 23:17:42 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void replace_content(std::ofstream &write_File, std::ifstream &read_File , \
std::string &strFind, std::string &strReplace)
{
	std::string		line;
	std::ofstream	writeFile;
	std::string		beforeRep;
	std::string		afterRep;
	std::size_t		pos;
	
	while (getline(read_File, line))
	{
		pos = line.find(strFind);//find from 0 position to end of line;
		while (pos != std::string::npos)
		{
			beforeRep = line.substr(0, pos);
			afterRep = line.substr(pos + strFind.length());
			line = beforeRep + strReplace + afterRep;
			pos = line.find(strFind, pos + strFind.length());//update to after strFind postion.
		}
		write_File << line << '\n';
	}
}

int main(int ac, char **av)
{
	std::ifstream	readFile;
	std::ofstream	writeFile;
	std::string		write_name;
	std::string		read_name;
	std::string		strFind;
	std::string		strReplace;
	
	if (ac != 4)
	{
		std::cerr << "\033[31m" << "Error: the program should takes three parameter." << "\033[0m" << '\n';
		return (EXIT_FAILURE);
	}	
	read_name	= (std::string) av[1];
	strFind		= (std::string) av[2];
	strReplace	= (std::string) av[3];
	readFile.open(read_name, std::ios::in);
	if (!readFile.is_open())
	{
		if (read_name.empty())
			std::cerr << "\033[31m" << "Error: filename should not be empty." << "\033[0m" << '\n';
		else
			std::cerr << "\033[31m" << "Error: File not found or unable to open." << "\033[0m" << '\n';
		return (EXIT_FAILURE);
	}
	if (strFind.empty())
	{
		std::cerr << "\033[31m" << "Error: finding string should not be empty." << "\033[0m" << '\n';
		return (EXIT_FAILURE);
	}
	write_name = read_name.substr(0, read_name.find_last_of(".")) + ".replace";
	writeFile.open(write_name, std::ios::out | std::ios::trunc);
	if (!writeFile.is_open())
	{
		std::cerr << "\033[31m" << "Error: outfile unable open." << "\033[0m" << '\n';
		return (readFile.close(), EXIT_FAILURE);
	}
	replace_content(writeFile, readFile, strFind, strReplace);
	readFile.close();
	writeFile.close();
	return (EXIT_SUCCESS);
}
