/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:26:06 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 22:26:20 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat"){

    this->type = "WrongCat";
    std::cout << "Derived: [WrongCat] created." << '\n';  
}

WrongCat::WrongCat(WrongCat const &instance): WrongAnimal(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "WrongCat copied." << '\n';
}

WrongCat::~WrongCat(void){
    
    std::cout << "Derived: [" << this->type << "] destroyed." << '\n';
}

WrongCat          &WrongCat::operator=(WrongCat const &instance){

        if (this != &instance)
            this->type = instance.type;
        return (*this);
}

void            WrongCat::makesound(void) const{

    std::cout << RED << "Meow ~" << DEFAULT << '\n';
}