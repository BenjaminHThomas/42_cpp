/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:07:39 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/30 10:46:02 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
	RPN performs Reverse Polish Notation for numbers between 0 & 9;
*/

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr  << "Error: invalid input - program takes a RPN string as the sole input.\n";
		return 1;
	}
	try {
		bool verbose = false;
		std::string input = av[1];
		RPN equation = RPN(input, verbose);
		equation.evalRPN();
	} catch (std::exception &e) {
		std::cerr << e.what();
	}
	return 0;
}