/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:47:14 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 23:53:22 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"){

    this->type = "Cat";
    std::cout << "Derived: [Cat] created." << '\n';  
}

Cat::Cat(Cat const &instance): Animal(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "Cat copied." << '\n';
}

Cat::~Cat(void){
    
    std::cout << "Derived: [Cat] destroyed." << '\n';
}

Cat          &Cat::operator=(Cat const &instance){

        if (this != &instance)
            this->type = instance.type;
        return (*this);
}

void            Cat::makesound(void) const{

    std::cout << ORANGE << "Meow ~" << DEFAULT << '\n';
}