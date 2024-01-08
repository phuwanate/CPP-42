/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:13:17 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/08 16:24:15 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization(void){
    
    std::cout << "Private Constructor called." << '\n';
}
Serialization::Serialization(Serialization const &inst){
    
    (void)inst;
}
Serialization::~Serialization(void){
    
}

Serialization &Serialization::operator=(Serialization const &inst){

    (void)inst;
    return *this;
}

uintptr_t Serialization::serialize(Data* ptr){
    
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw){

    return reinterpret_cast<Data *> (raw);   
}
