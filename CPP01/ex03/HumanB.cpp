/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:32:06 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/24 13:40:55 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(const char *name)
{
    this->_name = name;
    this->_club_type = NULL;
}

void        HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_club_type->getType() << '\n';
}

void        HumanB::setWeapon(Weapon &club)
{
    this->_club_type = &club;
}