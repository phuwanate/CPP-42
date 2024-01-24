/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:48 by plertsir          #+#    #+#             */
/*   Updated: 2024/01/24 12:36:34 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){

    if (ac < 2){
        std::cout << RED << "Error: Invalid argument." << '\n' << DEFAULT;
        return EXIT_FAILURE;
    }
    try{
        PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >  v(av + 1);
        std::cout << v;
        v.merge_insertion_sort();//before

        PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >  d(av + 1);
        d.merge_insertion_sort();//after
        std::cout << d;
        
        v.time_report();
        d.time_report();

    }catch(std::exception &e){
        std::cout << RED << e.what() << '\n' << DEFAULT;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}