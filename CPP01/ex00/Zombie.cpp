#include "Zombie.hpp"

Zombie::Zombie(std::string const &name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " was killed." << '\n';
}

void  Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}