/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:03:04 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/03 02:21:07 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){

    this->_brain = new Brain();
    this->_brain->setIdeas("Bark!");
    std::cout << "Derived: [Dog] created." << '\n';
}

Dog::Dog(Dog const &instance): Animal(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "Dog copied." << '\n';
}

Dog::~Dog(void){
    
    delete this->_brain;
    std::cout << "Derived: [Dog] destroyed." << '\n';
}

Brain        *Dog::getBrain(void) const{

    return (this->_brain);
}

Dog          &Dog::operator=(Dog const &instance){

        if (this != &instance)
        {
            this->type = instance.type;
            this->_brain = new Brain(*instance.getBrain());
        }
        return (*this);
}

void            Dog::makesound(void) const{

    std::cout << GREEN << "Bark !" << DEFAULT << '\n';
}

void        Dog::showIdeas(void){

    std::string *ideas = this->_brain->getIdeas();
    
    for (int i = 0; i < 100; i++)
    {
        std::cout << ideas[i] << " ";
        if ((i+1) % 10 == 0)
            std::cout << '\n';
    }
}