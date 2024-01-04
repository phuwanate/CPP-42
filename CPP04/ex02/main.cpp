/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:24:34 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/04 13:55:45 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void){

    //@Create Animal Class Test
    // Animal founding;

    //@Subject Test
    const Animal* a = new Dog(); 
    const Animal* b = new Cat();
    delete a;
    delete b;

    // //@Brain Test
    // std::cout << std::setfill('-') << std::setw(73) << '\n';
    // std::cout << GREEN << "Create Dog with Brain." << DEFAULT << '\n';
    // Dog i;
    // {
    //     Dog tmp = i;
    //     tmp.showIdeas();
    // }

    // std::cout << std::setfill('-') << std::setw(73) << '\n';
    // std::cout << ORANGE << "Create Cat with Brain." << DEFAULT << '\n';
    // Cat j;
    // {
    //     Cat tmp = j;
    //     tmp.showIdeas();
    // }

    return (EXIT_SUCCESS);
}