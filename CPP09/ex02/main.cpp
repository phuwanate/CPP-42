/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:48 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/21 14:19:39 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){

    if (ac < 2){
        std::cout << "Error: Invalid argument." << '\n';
        return EXIT_FAILURE;
    }
    try{
        PmergeMe<std::vector<int> >  v(av + 1);
        std::cout << v;
        v.merge_insertion_sort();//before

        PmergeMe<std::deque<int> >  d(av + 1);
        d.merge_insertion_sort();//after
        std::cout << d;
        
        v.time_report();
        d.time_report();

    }catch(std::exception &e){
        std::cout << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}