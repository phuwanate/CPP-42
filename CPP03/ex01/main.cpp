/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:39:56 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/03 18:54:02 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void){
    
    std::string name = "Jonathan";
    std::string name_2 = "Bro";
    ClapTrap champ_3(name_2);
    ScavTrap champ_1(name);
    ScavTrap champ_2(champ_1);

    champ_2.guardGate();
    for (int i = 0; i < 12; i++)
    {
        champ_2.attack(name_2);
        champ_3.takeDamage(20);
        champ_3.beRepaired(10);
    }
    return (EXIT_SUCCESS);
}