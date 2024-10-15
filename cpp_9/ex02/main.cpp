/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:43 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/15 19:05:06 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// example test: ./PmergeMe $(shuf -r -i 0-50000 -n 100000 | paste -sd " ") 
int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Please enter a series of positive integers separated by spaces for the input.\n";
		return 1;
	}
	try {
		PmergeMe pm(ac, av);
		pm.sortBoth();
	} catch (std::exception &e) {
		std::cerr << e.what();
	}
	return 0;
}