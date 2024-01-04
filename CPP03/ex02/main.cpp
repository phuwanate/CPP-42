/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:39:56 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/31 11:38:02 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
    
    std::string name = "Jonathan";
    std::string name_2 = "Bro";
    std::string name_3 = "Bro_2";
    ClapTrap champ_1(name_2);
    ScavTrap champ_2(name);
    ScavTrap champ_3(champ_2);
    FragTrap champ_4(name_3);

    champ_3.guardGate();
    champ_3.attack(name_2);
    champ_1.takeDamage(20);
    champ_4.highFivesGuys();
    champ_4.attack(name);
    champ_3.takeDamage(30);
    // for (int i = 0; i < 12; i++)
    // {
    //     champ_2.attack(name_2);
    //     champ_3.takeDamage(20);
    //     champ_3.beRepaired(10);
    // }
    return (EXIT_SUCCESS);
}