/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:17:20 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/08 22:37:55 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void){

    Base *a = generate();
    Base *b = generate();
    Base *c = generate();
    Base *d = generate();

    std::cout << "*a ";
    identify(a);
    std::cout << "&a ";
    identify(*a);
    std::cout << '\n';

    std::cout << "*b ";
    identify(b);
    std::cout << "&b ";
    identify(*b);
    std::cout << '\n';

    std::cout << "*c ";
    identify(c);
    std::cout << "&c ";
    identify(*c);
    std::cout << '\n';

    std::cout << "*d ";
    identify(d);
    std::cout << "&d ";
    identify(*d);

    return EXIT_SUCCESS;
}