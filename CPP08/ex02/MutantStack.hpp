#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>


template <class T>
class MutantStack: public std::stack<T>{

    public:
            MutantStack(void): std::stack<T>(){}
            MutantStack(MutantStack const& inst){
                *this = inst;
            }
            MutantStack &operator=(MutantStack const& inst){
                if (this != &inst)
                    std::stack<T>::operator=(inst);
                return *this;
            }
            ~MutantStack(void){}

            typedef typename std::stack<T>::container_type::iterator iterator;
            iterator begin(){ return std::stack<T>::c.begin(); }
            iterator end(){ return std::stack<T>::c.end(); }
};

#endif