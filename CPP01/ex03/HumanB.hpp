#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
                std::string _name;
                Weapon      *_club_type;//need to be pointer to weapon because constructor don't have weapon as a passed argument
    public:
                            HumanB(const char *name);
                void        attack(void);
                void        setWeapon(Weapon &club);
};

#endif