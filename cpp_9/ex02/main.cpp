/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:43 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/15 17:43:13 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Please enter a series of positive integers separated by spaces for the input.\n";
		return 1;
	}
	try {
		PmergeMe pm(ac, av);
		pm.sort();
	} catch (std::exception &e) {
		std::cerr << e.what();
	}
	return 0;
}