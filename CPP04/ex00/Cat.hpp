#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{

    public:
            				Cat(void);
							Cat(Cat const &instance);
			virtual			~Cat(void);
			Cat             &operator=(Cat const &instance);    
            void            makesound(void) const;
};

#endif