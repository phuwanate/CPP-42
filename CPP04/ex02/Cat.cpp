/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:47:14 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/03 02:21:18 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"){

    this->_brain = new Brain();
    this->_brain->setIdeas("Meow~");
    std::cout << "Derived: [Cat] created." << '\n';  
}

Cat::Cat(Cat const &instance): Animal(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "Cat copied." << '\n';
}

Cat::~Cat(void){
    
    delete this->_brain;
    std::cout << "Derived: [Cat] destroyed." << '\n';
}

Cat          &Cat::operator=(Cat const &instance){

        if (this != &instance)
        {
            this->type = instance.type;
            this->_brain = new Brain(*instance.getBrain());
        }
        return (*this);
}

Brain        *Cat::getBrain(void) const{

    return (this->_brain);
}

void            Cat::makesound(void) const{

    std::cout << ORANGE << "Meow ~" << DEFAULT << '\n';
}

void        Cat::showIdeas(void){

    std::string *ideas = this->_brain->getIdeas();
    
    for (int i = 0; i < 100; i++)
    {
        std::cout << ideas[i] << " ";
        if ((i+1) % 10 == 0)
            std::cout << '\n';
    }
}

