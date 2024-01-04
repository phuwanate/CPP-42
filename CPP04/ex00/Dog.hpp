#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{

    public:
            				Dog(void);
							Dog(Dog const &instance);
			virtual			~Dog(void);
			Dog             &operator=(Dog const &instance);    
            void            makesound(void) const;
};

#endif