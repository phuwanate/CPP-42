#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <iomanip>

class WrongAnimal {

    	protected:
			std::string     type;
	public:
							WrongAnimal(void);
							WrongAnimal(WrongAnimal const &instance);
							WrongAnimal(std::string const &_type);
							~WrongAnimal(void);
			WrongAnimal     &operator=(WrongAnimal const &instance);
	        void            makesound(void) const;
			std::string     getType(void) const;
};

#endif