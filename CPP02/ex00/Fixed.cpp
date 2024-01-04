/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:00:12 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/27 23:12:41 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fracVal = 8;

Fixed::Fixed(void){
    
    std::cout << "Default constructor called" << '\n';
    this->_numVal = 0;
}

Fixed::Fixed(Fixed const &instance){

    std::cout << "Copy constructor called" << '\n';
    if (this != &instance)
        *this = instance;
}

Fixed::~Fixed(void){

    std::cout << "Destructor called" << '\n';
}

Fixed &Fixed::operator=(Fixed const &instance){

    std::cout << "Copy assignment operator called" << '\n';
    if (this != &instance)
        this->_numVal = instance.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const{

    std::cout << "getRawBits member function called" << '\n';
    return (this->_numVal);
}

void Fixed::setRawBits( int const raw ){

    std::cout << "setRawBits member function called" << "\n";
    this->_numVal = raw;
}

