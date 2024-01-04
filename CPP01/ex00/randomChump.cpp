#include "Zombie.hpp"

void    randomChump(std::string name)
{
	Zombie  new_zomb(name);
	new_zomb.announce();
}