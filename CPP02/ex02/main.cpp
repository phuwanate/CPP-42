/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:16:37 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/27 23:02:26 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{ 
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
        return 0; 
}

// int main( void ) 
// { 
//         Fixed a(10.2023f);
//         Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//         Fixed c(9.2023f);
        
//         std::cout << "-------------------------------------" << '\n';
//         std::cout << "arithmetic operators: +, -, *, and /" << '\n';
//         std::cout << "-------------------------------------" << '\n';
//         std::cout << "a: " << a << std::endl;
//         std::cout << "b: " << b << std::endl;
//         std::cout << '\n';
//         std::cout << "a + b: ";
//         std::cout << a + b << std::endl;
//         std::cout << "a - b: ";
//         std::cout << a - b << std::endl;
//         std::cout << "a * b: ";
//         std::cout << a * b << std::endl;
//         std::cout << "a / b: ";
//         std::cout << a / b << std::endl;
        
//         std::cout << "-------------------------------------" << '\n';
//         std::cout << "The 4 increment/decrement: ++, --" << '\n';
//         std::cout << "-------------------------------------" << '\n';
//         std::cout << "a: " << a << std::endl;
//         std::cout << "b: " << b << std::endl;
//         std::cout << '\n';
//         std::cout << "a++: " << a++ << std::endl;
//         std::cout << "post: " << a << std::endl;
//         std::cout << "++a: " << ++a << std::endl;
//         std::cout << "post: " << a << std::endl;
//         std::cout << "a--: " << a-- << std::endl;
//         std::cout << "post: " << a << std::endl;
//         std::cout << "--a: " << --a << std::endl;
//         std::cout << "post: " << a << std::endl;

//         std::cout << "-------------------------------------" << '\n';
//         std::cout << "min, max function" << '\n';
//         std::cout << "-------------------------------------" << '\n';
//         std::cout << "a: " << a << std::endl;
//         std::cout << "b: " << b << std::endl;
//         std::cout << "c: " << c << std::endl;
//         std::cout << '\n';
//         std::cout << "min(a, b): ";
//         std::cout << Fixed::min(a, b) << '\n';
//         std::cout << "max(a, b): ";
//         std::cout << Fixed::max(a, b) << '\n';
//         std::cout << "min(a, c): ";
//         std::cout << Fixed::min(a, c) << '\n';
//         std::cout << "max(a, c): ";
//         std::cout << Fixed::max(a, c) << '\n';
//         return 0; 
// }