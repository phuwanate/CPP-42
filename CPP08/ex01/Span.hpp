#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span{
    private:
            unsigned int        _N;
            std::vector<int>    _container;
    public:
            Span(void);
            Span(unsigned int);
            ~Span(void);
            Span(Span const&);
            Span &operator=(Span const&);

            //getter
            void addNumber(unsigned int);

            //setter
            std::vector<int>  const& getContainer(void) const;

            class FullContainer: public std::exception{

                public:
                    virtual const char *what() const throw();
            };

            class DuplicatedNumber: public std::exception{

                public:
                    virtual const char *what() const throw();
            };
};

std::ostream &operator<<(std::ostream &o, Span const& inst);

#endif