#ifndef ARRAY_HPP
# define ARRAY_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <iostream>
#include <string>
#include <exception>

#pragma once

template <typename T>
class Array{
			private:
									T	*_elements;
						unsigned int	_N;
			public:
							//Constructors & Destructor
							Array( void ): _N( 0 ){
								
								// std::cout << "Default: Constructor called." << '\n';
								this->_elements = new T[ this->_N ];
							}
							Array( unsigned int N ): _N( N ){

								// std::cout << "unsigned int: Constructor called." << '\n';
								this->_elements = new T[ this->_N ];
							}
							Array( Array const & inst): _N( inst._N ){

								// std::cout << "Copy: Constructor called." << '\n';
								this->_elements = NULL;
								*this = inst;
							}
							~Array( void ){

								// std::cout << "Destructor called." << '\n';
								delete [] this->_elements;
							}

							//Overload assignment operator
					Array	&operator=( Array const &inst ){

								if (this->_elements != NULL)
									delete [] this->_elements;
								if (inst.getSize() != 0){

									this->_N = inst.getSize();
									this->_elements = new T[ this->_N ];
									for (unsigned int i = 0; i < this->getSize(); i++)
										this->_elements[i] = inst._elements[i];
								}
								return ( *this );
							}
					T		&operator[](unsigned int index){

								if (index >= this->getSize() || this->_elements == NULL)
								{
									std::cout << "[ INDEX ]: " << index << '\n';	
									throw Array<T>::Indexoutofbound();
								}
								return ( this->_elements[index] );
							}
					T const	&operator[](unsigned int index) const{

								if (index >= this->getSize() || this->_elements == NULL)
								{
									std::cout << "[ INDEX ]: " << index << '\n';	
									throw Array<T>::Indexoutofbound();
								}
								return ( this->_elements[index] );
							}
							
							//getter
			unsigned int	getSize(void) const{
								return ( this->_N );
							}

							//exception
					class	Indexoutofbound: public std::exception{ 
							
							public: 
									virtual const char	*what() const throw();
					};
};

template <typename T>
const char	*Array<T>::Indexoutofbound::what() const throw(){

	return "Error: Array index out of bound.";
}

#endif