/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:58:41 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/04 12:07:55 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _HitPoint(10), _EnergeyPoint(10), _AttackDamage(0){
    
    std::cout << "Default: ClapTrap created." << '\n';
}

ClapTrap::ClapTrap(ClapTrap	const &instance){

    if (this != &instance)
        *this = instance;
    std::cout << "ClapTrap [" << this->_Name << "] copy constructor called." << '\n';
}

ClapTrap::ClapTrap(std::string &Name): _Name(Name), \
_HitPoint(10), _EnergeyPoint(10), _AttackDamage(0){
    
    this->_Name = Name;
    std::cout << std::setfill('-') << std::setw(73) << '\n'; 
    std::cout << ORANGE;
    std::cout << "ClapTrap [" << this->_Name << "] created." << '\n';
    std::cout << DEFAULT;
    std::cout << "Status: [" << this->_Name << "]"  << '\n';
    std::cout << "-> " << "Hit point    : " << this->_HitPoint << '\n';
    std::cout << "-> " << "Energy point : " << this->_EnergeyPoint << '\n';
    std::cout << "-> " << "Attack damage: " << this->_AttackDamage << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n'; 
}

ClapTrap::~ClapTrap(void){
    
    std::cout << "ClapTrap [" << this->_Name << "] Destroyed." << '\n';
}

ClapTrap	    &ClapTrap::operator=(ClapTrap const &instance){

    if (this != &instance)
    {
        this->_Name = instance._Name;
        this->_HitPoint = instance._HitPoint;
        this->_EnergeyPoint = instance._EnergeyPoint;
        this->_AttackDamage = instance._AttackDamage;
    }
    std::cout << "ClapTrap " << "copy assignment called." << '\n';
    return (*this);
}

void ClapTrap::takeDamage(unsigned int amount){

    if (this->_HitPoint > 0)
    {
        if (amount >= this->_HitPoint)
        {
            std::cout << ORANGE << "Action: \"ClapTrap " << this->_Name << " takes [" << amount << "] points of damage!\"" << '\n';
            std::cout << "One shot!" << '\n';
            this->_HitPoint = 0;
        }
        else
        {  
            std::cout << ORANGE << "Action: \"ClapTrap " << this->_Name << " takes [" << amount << "] points of damage!\"" << '\n';
            this->_HitPoint -= amount;
        }
    }
    else
        std::cout << "\033[31m" << this->_Name << " can't take anymore damages " << " his HP is 0 already..." << '\n'; 
    std::cout << DEFAULT;
    std::cout << "Status: [" << this->_Name << "]"  << '\n';
    std::cout << "-> " << "Hit point    : " << this->_HitPoint << '\n';
    std::cout << "-> " << "Energy point : " << this->_EnergeyPoint << '\n';
    std::cout << "-> " << "Attack damage: " << this->_AttackDamage << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
}

void ClapTrap::attack(const std::string& target){

    if (this->_EnergeyPoint == 0)
        std::cout << RED << this->_Name << "\'s energy point is 0, It's impossible to attack..." << '\n';
    else if (this->_HitPoint == 0)
        std::cout << RED << this->_Name << "\'s HP is 0, need repairing...\"" << '\n';
    else
    {
        std::cout << ORANGE << "Action: \"ClapTrap " << this->_Name << " attacks "; 
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

void ClapTrap::beRepaired(unsigned int amount){

    if (this->_EnergeyPoint == 0)
        std::cout << RED << this->_Name << "\'s energy point is 0, It's impossible to repair...\"" << '\n';
    else if (this->_HitPoint == 10)
        std::cout << RED << "ClapTrap: " << this->_Name << " is healthy, It doesn't need to repair." << '\n';
    else if (this->_HitPoint == 0)
        std::cout << RED << this->_Name << "\'s hit point is 0, It's impossible to repair...\"" << '\n';
    else
    {
        std::cout << ORANGE << "Action: \"ClapTrap " << this->_Name << " repairing...\"" << '\n';
        if (this->_HitPoint > UINT_MAX - amount)
            this->_HitPoint = UINT_MAX;
        else
            this->_HitPoint += amount;
        this->_EnergeyPoint -=1;
    }
    std::cout << DEFAULT;
    std::cout << "Status: [" << this->_Name << "]"  << '\n';
    std::cout << "-> " << "Hit point    : " << this->_HitPoint << '\n';
    std::cout << "-> " << "Energy point : " << this->_EnergeyPoint << '\n';
    std::cout << "-> " << "Attack damage: " << this->_AttackDamage << '\n';
    std::cout << std::setfill('-') << std::setw(73) << '\n';
}
