/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:34:22 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/03 10:58:42 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
    if (N <= 0)
    {
        std::cout << "zombieHorde cannot be or less than zero." << '\n';
        return nullptr;
    }
    Zombie *zombies = new (std::nothrow) Zombie[N];
    if (!zombies)
        return (NULL);
    for (int i = 0; i < N; i++)
        zombies[i].get_name(name);
    return (&zombies[0]);
}