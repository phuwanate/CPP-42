#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* new_zomb = new (std::nothrow) Zombie (name);
    if (!new_zomb)
        return (NULL);
    return (new_zomb);
}