#include "Zombie.hpp"

Zombie::Zombie( void )
{
    //std::cout << "constructor was called" << '\n';
}

Zombie::~Zombie( void )
{
    //std::cout << "deconstructor was called" << '\n';
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}

void    Zombie::get_name(std::string const &str)
{
    this->name = str;
}
