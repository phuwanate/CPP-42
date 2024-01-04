/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:39:56 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/31 11:04:43 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
    
    std::string Name_1 = "Jonathan";
    std::string Name_2 = "Minion";

    ClapTrap champion(Name_1);
    ClapTrap minion(Name_2);
    ClapTrap champ2(champion);

    champ2.takeDamage(1000000);
    champ2.beRepaired(10);
    for (int i = 0; i < 10; i++)
    {
        champ2.attack(Name_2);
    }
    champ2.takeDamage(1000000);
    champ2.takeDamage(1000000);
    champ2.beRepaired(1);
}