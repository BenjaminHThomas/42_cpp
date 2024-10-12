/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:48 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/12 14:19:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: this program needs a filepath as the sole parameter.\n";
		return 1;
	}
	const std::string fname = av[1];
	try {
		BitcoinExchange btc;
		btc.printResults(fname);
	} catch (std::exception &e) {
		e.what();
	}
	return 0;
}