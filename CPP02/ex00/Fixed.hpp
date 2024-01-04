#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
					 int	_numVal;
		static int const    _fracVal;
	public:
							Fixed(void);
							Fixed(Fixed const &instance);
							~Fixed(void);
					Fixed	&operator=(Fixed const &instance);
					int		getRawBits( void ) const;
					void    setRawBits( int const raw );
};

#endif