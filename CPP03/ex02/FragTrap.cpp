/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:37:50 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/31 11:41:03 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(){

    this->_HitPoint = 100;
    this->_EnergeyPoint = 100;
    this->_AttackDamage = 30;
    std::cout << "Default: FragTrap created." << '\n';

}

FragTrap::FragTrap(std::string &Name): ClapTrap(Name){

    this->_Name = Name;
    this->_HitPoint = 100;
    this->_EnergeyPoint = 100;
    this->_AttackDamage = 30;
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << CYAN;
    std::cout << "FragTrap [" << this->_Name << "] created." << '\n';
    std::cout << DEFAULT;
    std::cout << "Status: [" << this->_Name << "]"  << '\n';
    std::cout << "-> " << "Hit point    : " << this->_HitPoint << '\n';
    std::cout << "-> " << "Energy point : " << this->_EnergeyPoint << '\n';
    std::cout << "-> " << "Attack damage: " << this->_AttackDamage << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
}

FragTrap::FragTrap(FragTrap	const &instance): ClapTrap(instance){
    
    if (this != &instance)
        *this = instance;
    std::cout << "FragTrap [" << this->_Name << "] copy constructor called." << '\n';
}

FragTrap::~FragTrap(void){

    std::cout << "FragTrap [" << this->_Name << "] Destroyed." << '\n';
} 

FragTrap    &FragTrap::operator=(FragTrap const &instance){

    if (this != &instance)
    {
        this->_Name = instance._Name;
        this->_HitPoint = instance._HitPoint;
        this->_EnergeyPoint = instance._EnergeyPoint;
        this->_AttackDamage = instance._AttackDamage;
    }
    std::cout << "FragTrap copy assignment called." << '\n';
    return (*this);
}

void    FragTrap::attack(const std::string& target){

    if (this->_EnergeyPoint == 0)
        std::cout << RED << this->_Name << "\'s energy point is 0, It's impossible to attack..." << '\n';
    else if (this->_HitPoint == 0)
        std::cout << RED << this->_Name << "\'s HP is 0, need repairing...\"" << '\n';
    else
    {
        std::cout << CYAN << "Action: \"FragTrap " << this->_Name << " attacks "; 
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

void FragTrap::highFivesGuys(void){
    
    std::cout << std::setfill('-') << std::setw(73) << '\n';
    std::cout << CYAN;
    std::cout << "Action: \"FragTrap " << this->_Name << " want to highFives!\"" << '\n';
    std::cout << DEFAULT;
    std::cout << std::setfill('-') << std::setw(73) << '\n';
}