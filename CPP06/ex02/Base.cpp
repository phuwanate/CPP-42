/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:02:11 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/10 19:12:47 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void){

}

Base *generate(void){
    
    if (std::rand() % 3 == 0)
        return ( new A );
    else if (std::rand() % 3 == 1)
        return ( new B );
    else
        return ( new C );
}

void identify(Base* p){
    //Base->?    
    //Null ptr will return if cast failed
    if (dynamic_cast< A *>( p ))
        std::cout << "-> \"A\"" << '\n';
    else if (dynamic_cast< B *>( p ))
        std::cout << "-> \"B\"" << '\n';
    else if (dynamic_cast< C *>( p ))
        std::cout << "-> \"C\"" << '\n';
}
void identify(Base& p){
    
    //cast reference fail return bad_cast
    try{
        A &a = dynamic_cast< A &>( p );
        (void)a;
        std::cout << "-> \"A\"" << '\n';
    }catch(std::bad_cast &e){ }
    try{
        B &b = dynamic_cast< B &>( p );
        (void)b;
        std::cout << "-> \"B\"" << '\n';
    }catch(std::bad_cast &e){ }
    try {
        C &c = dynamic_cast< C &>( p );
        (void)c;
        std::cout << "-> \"C\"" << '\n';
    }catch(std::bad_cast &e){ }
}