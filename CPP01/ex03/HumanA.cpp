/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:08:16 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/03 10:50:05 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const char *name, Weapon &club): _name(name), _club_type(club)
{
    // this->_name = name;
    // this->_club_type = club;
}

void        HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_club_type.getType() << '\n';
}