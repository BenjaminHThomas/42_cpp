/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:48 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/11 17:22:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: this program needs a filepath as the sole parameter.\n";
		return 1;
	}
	const std::string fname = av[1];
	BitcoinExchange btc(fname);
	btc.debugPrint();
	return 0;
}