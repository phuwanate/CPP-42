/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:30:58 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/22 21:01:49 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int      zomb_nb = 5;
    Zombie  *zombies = zombieHorde(zomb_nb, "zomboy");
    
    if (!zombies)
    {
        std::cout << "Bad alloc" << '\n';
        return (EXIT_FAILURE);
    }
    for (int i = 0; i < zomb_nb; i++)
        zombies[i].announce();
    delete []zombies;
    return (EXIT_SUCCESS);
}