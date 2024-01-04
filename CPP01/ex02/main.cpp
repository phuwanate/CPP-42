/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:31:43 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/22 23:39:52 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << '\n';

    std::cout << &str << '\n';
    std::cout << stringPTR << '\n';
    std::cout << &stringREF << '\n';
    
    std::cout << '\n';
    
    std::cout << str << '\n';
    std::cout << *stringPTR << '\n'; //this is pointer need to dereference
    std::cout << stringREF << '\n'; //this is str itself no need to dereference
}