#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{

	private:
			Brain			*_brain;
    public:
            				Cat(void);
							Cat(Cat const &instance);
			virtual			~Cat(void);
			Cat             &operator=(Cat const &instance);    
            void            makesound(void) const;
			void        	showIdeas(void);
			Brain			*getBrain(void) const;
};

#endif