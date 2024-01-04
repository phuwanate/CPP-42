/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:24:34 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 23:52:50 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void){

    //@Animal Class Test
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "Animal Class Test" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "-> CREATE PHASE <-" << '\n';
    const Animal* meta = new Animal();
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "-> ANIMAL: TYPE <-" << '\n';
    std::cout << CYAN << meta->getType() << " " << std::endl;
    std::cout << GREEN << i->getType() << " " << std::endl;
    std::cout << ORANGE << j->getType() << " " << std::endl;
    std::cout << DEFAULT;
    
    std::cout << "-> ANIMAL: SOUND <-" << '\n';
    std::cout << CYAN << meta->getType() << ": ";
    meta->makesound();//Animal sound
    std::cout << GREEN << i->getType() << ": ";
    i->makesound();//dog sound
    std::cout << ORANGE << j->getType() << ": ";
    j->makesound();//cat sound
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "-> DESTROY PHASE <-" << '\n';
    delete meta;
    delete i;
    delete j;
    std::cout << std::setfill('-') << std::setw(73) << '\n';

    //@WrongAnimal Class Test
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "WrongAnimal Class Test" << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "-> CREATE PHASE <-" << '\n';
    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "-> WRONG ANIMAL: TYPE <-" << '\n';
    std::cout << RED << wrongmeta->getType() << " " << std::endl;
    std::cout << RED << k->getType() << " " << std::endl;
    std::cout << DEFAULT;

    std::cout << "-> WRONG ANIMAL: SOUND <-" << '\n';
    std::cout << RED << wrongmeta->getType() << ": ";
    wrongmeta->makesound();//WrongAnimal sound
    std::cout << RED << k->getType() << ": ";
    k->makesound();//WrongCat sound
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << "-> DESTROY PHASE <-" << '\n';
    delete wrongmeta;
    delete k;
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    
    return (EXIT_SUCCESS);
}