/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:41:11 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 23:54:54 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal"){

    std::cout << "Base:    [" << this->type << "] created." << '\n';
}

Animal::Animal(Animal const &instance){

    if (this != &instance)
        *this = instance;
    std::cout << "Animal copied." << '\n';
}

Animal::Animal(std::string const &_type): type(_type){

    std::cout << "Base:    [" << this->type << "] created." << '\n';
}

Animal::~Animal(void){

    std::cout << "Base:    [" << this->type << "] destroyed." << '\n';
}

Animal          &Animal::operator=(Animal const &instance){

        if (this != &instance)
            this->type = instance.type;
        return (*this);
}

void    Animal::makesound(void) const{

    std::cout << CYAN << "???" <<'\n';
}

std::string     Animal::getType(void) const{

    return (this->type);
}