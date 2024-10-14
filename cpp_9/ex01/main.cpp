/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:07:39 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/14 15:35:15 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr  << "Error: invalid input - program takes a RPN string as the sole input.\n";
		return 1;
	}
	try {
		bool verbose = false;
		RPN equation = RPN(av[1], verbose);
		equation.debugPrint();
		equation.execute();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}