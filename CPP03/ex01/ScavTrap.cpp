/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:03:04 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/02 18:38:37 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(){

    this->_HitPoint = 100;
    this->_EnergeyPoint = 50;
    this->_AttackDamage = 20;
    std::cout << "Default: ScavTrap created." << '\n';

}

ScavTrap::ScavTrap(std::string &Name): ClapTrap(Name){

    this->_Name = Name;
    this->_HitPoint = 100;
    this->_EnergeyPoint = 50;
    this->_AttackDamage = 20;
    std::cout << std::setfill('-') << std::setw(73) << '\n'; 
    std::cout << GREEN;
    std::cout << "ScavTrap [" << this->_Name << "] created." << '\n';
    std::cout << DEFAULT;
    std::cout << "Status: [" << this->_Name << "]"  << '\n';
    std::cout << "-> " << "Hit point    : " << this->_HitPoint << '\n';
    std::cout << "-> " << "Energy point : " << this->_EnergeyPoint << '\n';
    std::cout << "-> " << "Attack damage: " << this->_AttackDamage << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n'; 
}

ScavTrap::ScavTrap(ScavTrap	const &instance): ClapTrap(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "ScavTrap [" << this->_Name << "] copy constructor called." << '\n';
}

ScavTrap::~ScavTrap(void){

    std::cout << "ScavTrap [" << this->_Name << "] Destroyed." << '\n';
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &instance){

    if (this != &instance)
    {
        this->_Name = instance._Name;
        this->_HitPoint = instance._HitPoint;
        this->_EnergeyPoint = instance._EnergeyPoint;
        this->_AttackDamage = instance._AttackDamage;
    }
    std::cout << "ScavTrap copy assignment called." << '\n';
    return (*this);
}

void    ScavTrap::attack(const std::string& target){

    if (this->_EnergeyPoint == 0)
        std::cout << RED << this->_Name << "\'s energy point is 0, It's impossible to attack..." << '\n';
    else if (this->_HitPoint == 0)
        std::cout << RED << this->_Name << "\'s HP is 0, need repairing...\"" << '\n';
    else
    {
        std::cout << GREEN << "Action: \"ScavTrap " << this->_Name << " attacks "; 
        std::cout << target << ", causing " << this->_AttackDamage << " points of damage!\"" << '\n';
        this->_EnergeyPoint -=1;  
    }
    std::cout << DEFAULT;
    std::cout << "Status: [" << this->_Name << "]" << '\n';
    std::cout << "-> " << "Hit point    : " << this->_HitPoint << '\n';
    std::cout << "-> " << "Energy point : " << this->_EnergeyPoint << '\n';
    std::cout << "-> " << "Attack damage: " << this->_AttackDamage << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';    
}

void    ScavTrap::guardGate(void){
    std::cout << std::setfill('-') << std::setw(73) << '\n'; 
    std::cout << GREEN;
    std::cout << "Action: \"ScavTrap [" << this->_Name << "] is now in Gate keeper mode.\"" << '\n';
    std::cout << DEFAULT;
    std::cout << std::setfill('-') << std::setw(73) << '\n'; 
}

