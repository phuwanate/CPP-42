#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{

    public:
                    FragTrap(void);
                    FragTrap(FragTrap	const &instance);
                    FragTrap(std::string &Name);
                    ~FragTrap(void);
        FragTrap    &operator=(FragTrap const &instance);
            void    attack(const std::string& target);
            void    highFivesGuys(void);
};

#endif