/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:00:12 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/27 23:11:26 by plertsir         ###   ########.fr       */
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

Fixed::Fixed(int const intVal){

    std::cout << "Int constructor called" << '\n';
    this->_numVal = intVal << this->_fracVal;
}

Fixed::Fixed(float const floatVal){

    std::cout << "Float constructor called" << '\n';
    this->_numVal = roundf(floatVal * (1 << this->_fracVal));
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

    // std::cout << "getRawBits member function called" << '\n';
    return (this->_numVal);
}

void Fixed::setRawBits( int const raw ){

    // std::cout << "setRawBits member function called" << "\n";
    this->_numVal = raw;
}

float	Fixed::toFloat( void ) const{

    return ((float)this->_numVal / (1 << this->_fracVal)); 
}

int Fixed::toInt( void ) const{

    return ((int)(this->_numVal >> this->_fracVal));
}

std::ostream &operator<<(std::ostream &o, Fixed const &instance){

    o << instance.toFloat();
    return o;
}