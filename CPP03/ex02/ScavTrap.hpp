#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
                    ScavTrap(void);
                    ScavTrap(ScavTrap	const &instance);
                    ScavTrap(std::string &Name);
                    ~ScavTrap(void);
        ScavTrap    &operator=(ScavTrap const &instance);
            void    attack(const std::string& target);
            void    guardGate();
};

#endif