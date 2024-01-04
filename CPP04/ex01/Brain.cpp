/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:23:48 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/03 02:27:54 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){

    std::cout << CYAN << "Brain created." << DEFAULT << '\n';
}

Brain::Brain(Brain const &instance){

    if (this != &instance)
        *this = instance;
    std::cout << CYAN << "Brain deep copied." << DEFAULT << '\n';
}

Brain::~Brain(void){

    std::cout << CYAN << "Brain destroyed." << DEFAULT << '\n';
}

Brain          &Brain::operator=(Brain const &instance){

        if (this != &instance)
        {
            for (int i = 0; i < 100; i++)
                this->ideas[i] = instance.ideas[i];
        }
        return (*this);  
}

void        Brain::setIdeas(std::string idea){

    for (int i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

std::string 	*Brain::getIdeas(void){

    return (ideas);
}
