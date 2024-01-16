#include "Span.hpp"

Span::Span(void){}

Span::Span(unsigned int N): _N(N){}

Span::~Span(void){}

Span::Span(Span const& inst){
    *this = inst;
}

Span &Span::operator=(Span const& inst){
    if (this != &inst)
    {
        this->_container.clear();
        this->_N = inst._N;
        this->_container = inst._container;
    }
    return *this;
}

void Span::addNumber(unsigned int newNum){

    if (this->_container.size() >= _N){
        throw Span::FullContainer();
    }
    else if (std::find(this->_container.begin(), this->_container.end(), newNum) == this->_container.end())
        this->_container.push_back(newNum);
    else
        throw Span::DuplicatedNumber();
}

const char* Span::FullContainer::what() const throw(){

    return "Error: This container is already full.";
}

const char* Span::DuplicatedNumber::what() const throw(){

    return "Error: Duplicated number.";
}

std::vector<int>  const& Span::getContainer(void) const{

    return (this->_container);
}

std::ostream &operator<<(std::ostream &o, Span const& inst){

    std::vector<int>::const_iterator it = inst.getContainer().begin();
    while (it != inst.getContainer().end())
    {
        o << *it << " ";
        it++;
    }
    o << std::endl;
    return o;
}