#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(const char *weapon_type)
{
	this->_type = weapon_type;
}

Weapon::~Weapon(void)
{

}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string const &str)
{
	this->_type = str;
}