/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:01:15 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/08 15:52:35 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

ScalarConverter::ScalarConverter(void){

  std::cout << "Private Constructor Called" << '\n'; 
}

ScalarConverter::~ScalarConverter(void){

    
}

ScalarConverter::ScalarConverter(ScalarConverter const &inst){

    (void) inst;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &inst){

    (void) inst;
    return *this;
}

bool    ScalarConverter::convert(std::string arg){

    std::string _str = arg;
    arg_type    _type;
    
    checkType(arg, _type);
    if (_type == NONE)
        return false;
    typeCast(arg, _type);
    return true;
}
