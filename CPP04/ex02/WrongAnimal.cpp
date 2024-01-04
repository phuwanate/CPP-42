/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:16:29 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 22:16:58 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal"){

    std::cout << "Base:    [" << this->type << "] created." << '\n';
}

WrongAnimal::WrongAnimal(WrongAnimal const &instance){

    if (this != &instance)
        *this = instance;
    std::cout << "WrongAnimal copied." << '\n';
}

WrongAnimal::WrongAnimal(std::string const &_type): type(_type){

    std::cout << "Base:    [" << this->type << "] created." << '\n';
}

WrongAnimal::~WrongAnimal(void){

    std::cout << "Base:    ["<< this->type << "] destroyed." << '\n';
}

WrongAnimal          &WrongAnimal::operator=(WrongAnimal const &instance){

        if (this != &instance)
            this->type = instance.type;
        return (*this);
}

void    WrongAnimal::makesound(void) const{

    std::cout << RED << "XXX" << DEFAULT <<'\n';
}

std::string     WrongAnimal::getType(void) const{

    return (this->type);
}