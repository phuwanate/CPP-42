#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{

	private:
			Brain			*_brain;
    public:
            				Dog(void);
							Dog(Dog const &instance);
			virtual			~Dog(void);
			Dog             &operator=(Dog const &instance);
            void            makesound(void) const;
			void        	showIdeas(void);
			Brain			*getBrain(void) const;
};

#endif