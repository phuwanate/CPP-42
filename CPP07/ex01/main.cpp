/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:57:33 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/09 23:31:26 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void){

    int arr_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string arr_str[] = {"cat", "dog", "zombie", "pizza", "sky"};
    
    iter(arr_int, -1, &call_arr<int>);
    iter(arr_int, getSize(arr_int), &call_arr<int>);
    iter(arr_str, getSize(arr_str), &call_arr<std::string>);

    // int arr1[] = { 1, 2, 3, 4, 5 };
    
    // std::cout << "arr1: " << std::endl;
    // iter(arr1, getSize(arr1), &call_arr);

    // double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    // std::cout << "\narr2: " << std::endl;
    // iter(arr2, getSize(arr2), &call_arr);

    // char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    // std::cout << "\narr3: " << std::endl;
    // iter(arr3, getSize(arr3), &call_arr);

    // std::string arr4[] = { "one", "two", "three", "four", "five" };

    // std::cout << "\narr4: " << std::endl;
    // iter(arr4, getSize(arr4), &call_arr);
    return 0;
}