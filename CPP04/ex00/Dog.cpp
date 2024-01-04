/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:03:04 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 23:41:11 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){

    this->type = "Dog";
    std::cout << "Derived: [Dog] created." << '\n';  
}

Dog::Dog(Dog const &instance): Animal(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "Dog copied." << '\n';
}

Dog::~Dog(void){
    
    std::cout << "Derived: [Dog] destroyed." << '\n';
}

Dog          &Dog::operator=(Dog const &instance){

        if (this != &instance)
            this->type = instance.type;
        return (*this);
}

void            Dog::makesound(void) const{

    std::cout << GREEN << "Bark !" << DEFAULT << '\n';
}