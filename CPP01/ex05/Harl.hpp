#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
				void	debug(void);
				void	info(void);
				void	waring(void);
				void	error(void);
	public:
				void	complain(std::string level);
		typedef	void	(Harl::*func_ptr)();
};

#endif