/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:17:20 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/08 17:33:07 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(void){

    Data *ptr = new Data();
    ptr->name = "flank";
    ptr->age = 100;
    
    std::cout << "Data* to uintptr_t" << '\n';
    std::cout << "Address(Hex): " << ptr << '\n';
    uintptr_t   data_to_uint = Serialization::serialize(ptr);
    std::cout << "Address(uintptr_t): " << data_to_uint << '\n'; // convert the memory address held by the pointer from hexa to uint pointer. 
    std::cout << "------------------------------------" << '\n';
    Data        *ptr_to_data = Serialization::deserialize(data_to_uint);
    std::cout << "uintptr_t to Data*" << '\n';
    std::cout << "name: " << ptr_to_data->name << '\n';
    std::cout << "age: " << ptr_to_data->age << '\n';  
    std::cout << "------------------------------------" << '\n';
}