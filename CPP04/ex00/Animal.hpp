#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#define ORANGE "\033[38;2;255;165;0m"
#define DEFAULT "\033[0m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <iomanip>

class Animal{
	
	protected:
			std::string     type;
	public:
							Animal(void);
							Animal(std::string const &_type);
							Animal(Animal const &instance);
			virtual			~Animal(void);
			Animal          &operator=(Animal const &instance);
	virtual void            makesound(void) const;
			std::string     getType(void) const;
};

#endif