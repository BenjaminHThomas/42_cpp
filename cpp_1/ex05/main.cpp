/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/29 10:45:28 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

void	test(int numComplaints) {
	Harl harl;

	srand(time(0));
	for (int i = 0; i < numComplaints; ++i) {
		int choice = (rand() % 4);
		switch (choice) {
			case 0:
				std::cout << "Debug chosen: ";
				harl.complain("debug");
			case 1:
				std::cout << "Info chosen: ";
				harl.complain("info");
			case 2:
				std::cout << "Warning chosen: ";
				harl.complain("warning");
			case 3:
				std::cout << "Error chosen: ";
				harl.complain("error");
		}
	}
}

int	main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	Harl harl;
	std::cout << "user choice:\n";
	harl.complain(argv[1]);
	std::cout << "\nautomated testing: \n";
	test(5);
	return (0);
}