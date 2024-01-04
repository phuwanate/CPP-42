/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:00:12 by plertsir          #+#    #+#             */
/*   Updated: 2023/12/27 23:11:10 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fracVal = 8;

Fixed::Fixed(void){

    this->_numVal = 0;
}

Fixed::Fixed(Fixed const &instance){

    if (this != &instance)
        *this = instance;
}

Fixed::Fixed(int const intVal){

    this->_numVal = intVal << this->_fracVal;
}

Fixed::Fixed(float const floatVal){

    this->_numVal = roundf(floatVal * (1 << this->_fracVal));
}

Fixed::~Fixed(void){

    // std::cout << "Destructor called" << '\n';
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

//Overload part
Fixed &Fixed::operator=(Fixed const &instance){

    if (this != &instance)
        this->_numVal = instance.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &instance){

    o << instance.toFloat();
    return o;
}

bool	Fixed::operator>(Fixed const &instance) const{

    return (this->toFloat() > instance.toFloat());
}

bool	Fixed::operator<(Fixed const &instance) const{

    return (this->toFloat() < instance.toFloat());
}

bool	Fixed::operator>=(Fixed const &instance) const{

    return (this->toFloat() >= instance.toFloat());
}

bool	Fixed::operator<=(Fixed const &instance) const{

    return (this->toFloat() <= instance.toFloat());
}

bool	Fixed::operator==(Fixed const &instance) const{

    return (this->toFloat() == instance.toFloat());
}

bool	Fixed::operator!=(Fixed const &instance) const{

    return (this->toFloat() != instance.toFloat());
}

float	Fixed::operator+(Fixed const &instance) const{

    return (this->toFloat() + instance.toFloat());
}

float	Fixed::operator-(Fixed const &instance) const{

    return (this->toFloat() - instance.toFloat());
}

float	Fixed::operator*(Fixed const &instance) const{

    return (this->toFloat() * instance.toFloat());
}

float	Fixed::operator/(Fixed const &instance) const{
    
    return (this->toFloat() / instance.toFloat());
}

Fixed	Fixed::operator++(int){

    Fixed tmp = *this;
    // this->_numVal += (1 << this->_fracVal);
    this->_numVal += 1;
    return (tmp);
}

Fixed	&Fixed::operator++(void){
    
    // this->_numVal += (1 << this->_fracVal);
    this->_numVal += 1;
    return (*this);
}

Fixed	Fixed::operator--(int){
    
    Fixed tmp = *this;
    // this->_numVal -= (1 << this->_fracVal);
    this->_numVal -= 1;
    return (tmp);
}

Fixed	&Fixed::operator--(void){
    
    // this->_numVal -= (1 << this->_fracVal);
    this->_numVal -= 1;
    return (*this);
}

//Static function
Fixed	&Fixed::min(Fixed &ins1, Fixed &ins2){
    if (ins1 <= ins2)
        return ins1;
    else
        return ins2;
}

Fixed	const &Fixed::min(Fixed const &ins1, Fixed const &ins2){
    if (ins1 <= ins2)
        return ins1;
    else
        return ins2;
}

Fixed	&Fixed::max(Fixed &ins1, Fixed &ins2){
    if (ins1 >= ins2)
        return ins1;
    else
        return ins2;
}

Fixed	const &Fixed::max(Fixed const &ins1, Fixed const &ins2){
    if (ins1 >= ins2)
        return ins1;
    else
        return ins2;
}






