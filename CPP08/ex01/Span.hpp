#ifndef SPAN_HPP
# define SPAN_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

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

            //setter
            void addNumber(unsigned int);
            void addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite);

            //getter
            std::vector<int>  const& getContainer(void) const;

            unsigned int shortestSpan(void);
            unsigned int longestSpan(void);

            class FullContainer: public std::exception{

                public:
                    virtual const char *what() const throw();
            };

            class DuplicatedNumber: public std::exception{

                public:
                    virtual const char *what() const throw();
            };

            class AddContainer: public std::exception{

                public:
                    virtual const char *what() const throw();
            };

            class NoSpanFound: public std::exception{

                public:
                    virtual const char *what() const throw();
            };
};

std::ostream &operator<<(std::ostream &o, Span const& inst);

#endif