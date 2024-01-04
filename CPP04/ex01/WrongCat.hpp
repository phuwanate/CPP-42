#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{

    public:
            				WrongCat(void);
							WrongCat(WrongCat const &instance);
							~WrongCat(void);
			WrongCat        &operator=(WrongCat const &instance);    
            void            makesound(void) const;
};

#endif