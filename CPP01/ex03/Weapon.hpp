#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
                std::string             _type;
    public:
                                        Weapon();
                                        Weapon(const char *weapon_type);
                                        ~Weapon(void);
                const std::string&      getType(void);
                void                    setType(std::string const &str);
};

#endif