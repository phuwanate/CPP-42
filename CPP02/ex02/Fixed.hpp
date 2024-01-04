#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
					int		_numVal;
	static	const	int		_fracVal;
	public:
							Fixed(void);
							Fixed(Fixed	const &instance);
							Fixed(int 	const intVal);
							Fixed(float const floatVal);
							~Fixed(void);
					int		getRawBits( void ) const;
					void    setRawBits( int const raw );
					float	toFloat( void ) const;
					int		toInt( void ) const;
					bool	operator>(Fixed const &instance) const;
					bool	operator<(Fixed const &instance) const;
					bool	operator>=(Fixed const &instance) const;
					bool	operator<=(Fixed const &instance) const;
					bool	operator==(Fixed const &instance) const;
					bool	operator!=(Fixed const &instance) const;
					float	operator+(Fixed const &instance) const;
					float	operator-(Fixed const &instance) const;
					float	operator*(Fixed const &instance) const;
					float	operator/(Fixed const &instance) const;
					Fixed	&operator=(Fixed const &instance);
					Fixed	operator++(int);
					Fixed	operator--(int);
					Fixed	&operator++(void);
					Fixed	&operator--(void);
			static	Fixed	&min(Fixed &ins1, Fixed &ins2);
	static	const 	Fixed	&min(Fixed const &ins1, Fixed const &ins2);
			static	Fixed	&max(Fixed &ins1, Fixed &ins2);
	static	const 	Fixed	&max(Fixed const &ins1, Fixed const &ins2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &instance);

#endif