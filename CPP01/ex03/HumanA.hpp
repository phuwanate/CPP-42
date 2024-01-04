#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
                std::string _name;
                Weapon      &_club_type;//can be reference to weapon because constructor have weapon as a passed argument
    public:
                            HumanA(const char *name, Weapon &club);
                void        attack(void);
};

#endif