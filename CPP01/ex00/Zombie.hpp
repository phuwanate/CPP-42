#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>


class Zombie
{
    private:
            std::string     name;
    public:
            Zombie          *ptr;
                            Zombie(std::string const &name);
                            ~Zombie(void);
            void            announce(void);
};

Zombie*         newZombie(std::string name);
void            randomChump(std::string name);

#endif