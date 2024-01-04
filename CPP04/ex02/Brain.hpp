#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain{

    private:
        std::string     ideas[100];
    public:
                        Brain(void);
					    Brain(Brain const &instance);
			virtual		~Brain(void);
			Brain       &operator=(Brain const &instance);
            void        setIdeas(std::string idea);
            std::string *getIdeas(void);
};

#endif