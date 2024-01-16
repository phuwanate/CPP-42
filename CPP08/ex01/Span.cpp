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

    try{
        if (this->_container.size() == _N)
            throw Span::FullContainer();
        else if (std::find(this->_container.begin(), this->_container.end(), newNum) == this->_container.end())
            this->_container.push_back(newNum);
        else
            throw Span::DuplicatedNumber();
        }catch(std::exception &e){
            std::cout << RED << e.what() << '\n' << DEFAULT;
        }
}

void Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite){

    try{
            if (this->_container.size() == _N)
                throw Span::FullContainer();
            else if (std::distance(it, ite) + this->_container.size() > _N)
                throw Span::AddContainer();
            for(std::vector<int>::iterator head = it; head != ite; head++){

                if (std::find(this->_container.begin(), this->_container.end(), *head) == this->_container.end())
                    this->_container.push_back(*head);
                else
                    throw Span::DuplicatedNumber();
            }
        }catch(std::exception &e){
            std::cout << RED << e.what() << '\n' << DEFAULT;
    }
}

unsigned int Span::shortestSpan(void){

    try{
        if (this->_container.size() <= 1)
            throw Span::NoSpanFound();
        std::vector<int>::iterator it = this->_container.begin();
        std::vector<int>::iterator ite = this->_container.end();
        std::vector<int>::iterator next = it + 1;
        unsigned int tmp;
        unsigned int shortest = UINT_MAX;

        std::sort(it, ite);
        while (next != ite){
            tmp = *next - *it;
            if (tmp < shortest)
                shortest = tmp;
            next++; 
            it++;
        }
        return shortest;
    }catch(std::exception &e){
        std::cout << RED << e.what() << '\n' << DEFAULT;
    }
    return EXIT_FAILURE;
}

unsigned int Span::longestSpan(void){

    try{
        if (this->_container.size() <= 1)
            throw Span::NoSpanFound();
        std::vector<int>::iterator max = std::max_element(this->_container.begin(), this->_container.end());
        std::vector<int>::iterator min = std::min_element(this->_container.begin(), this->_container.end());
        return (static_cast<unsigned int>(*max - *min));
    }catch(std::exception &e){
        std::cout << RED << e.what() << '\n' << DEFAULT;
    }
    return EXIT_FAILURE;
}

const char* Span::FullContainer::what() const throw(){ return "Error: This container is already full."; }

const char* Span::AddContainer::what() const throw(){ return "Error: Please fixed the set of numbers."; }

const char* Span::DuplicatedNumber::what() const throw(){ return "Error: Duplicated number."; }

const char* Span::NoSpanFound::what() const throw(){ return "Error: No span can be found."; }

std::vector<int>  const& Span::getContainer(void) const{

    return (this->_container);
}

std::ostream &operator<<(std::ostream &o, Span const& inst){

    std::vector<int>::const_iterator it = inst.getContainer().begin();
    o << "Container: [ ";
    while (it != inst.getContainer().end())
    {
        o << *it << " ";
        it++;
    }
    o << "]" << std::endl;
    return o;
}