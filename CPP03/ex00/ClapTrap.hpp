#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap
{
    private:
                std::string     _Name;
                unsigned int    _HitPoint;
                unsigned int    _EnergeyPoint;
                unsigned int    _AttackDamage;
    public:
                                ClapTrap(void);
                                ClapTrap(ClapTrap	const &instance);
                                ClapTrap(std::string &Name);
                                ~ClapTrap(void);
                ClapTrap	    &operator=(ClapTrap const &instance);
                void            attack(const std::string& target);
                void            takeDamage(unsigned int amount);
                void            beRepaired(unsigned int amount);
};

#endif