/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:45:02 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/10 00:01:58 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void){
    
    std::cout << "[ Mandatory Test ]" << '\n';

    Array<int> empty;
    Array<int> arr_int(10);
    Array<double> arr_double(10);
    Array<std::string> arr_str(3);

    arr_str[0] = "Cat";
    arr_str[1] = "Pizza";
    arr_str[2] = "Foo";

    for (int i = 0; i < 3; i++)
        std::cout << arr_str[i] << " ";
    std::cout << '\n';

    for (int i = 0; i < 10; i++)
        arr_double[i] = i + 1.5;

    for (int i = 0; i < 10; i++)
        arr_int[i] = i + 1;
    
    for (int i = 0; i < 10; i++)
        std::cout << arr_int[i] << " ";
    std::cout << '\n';   
    
    for (int i = 0; i < 10; i++)
        std::cout << arr_double[i] << " ";
    std::cout << '\n';
    
    std::cout << "////////////////////////////////////////////////////////////" << '\n';
    std::cout << '\n';
    std::cout << "[ Const instance: Reading Only test ]" << '\n';
    const Array<std::string> immu_string = static_cast <const Array<std::string> >(arr_str);
    const Array<int> immu_int = static_cast <const Array<int> >(arr_int);
    const Array<double> immu_double = static_cast <const Array<double> >(arr_double);
    
    for (int i = 0; i < 3; i++)
        std::cout << arr_str[i] << " ";
    std::cout << '\n';
    
    for (int i = 0; i < 10; i++)
        std::cout << immu_int[i] << " ";
    std::cout << '\n';

    for (int i = 0; i < 10; i++)
        std::cout << arr_double[i] << " ";
    std::cout << '\n';
    
    //These will not work with const instance.
    // immu_int[0] = 10000;
    std::cout << "////////////////////////////////////////////////////////////" << '\n';
    
    return 0;
}

// Subject test
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }