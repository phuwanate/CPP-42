#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

#include <iostream>
#include <string>
#include <iomanip> 


class ClapTrap
{
    protected:
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