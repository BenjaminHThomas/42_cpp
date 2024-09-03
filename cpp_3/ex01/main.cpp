/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:36:51 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 10:43:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap bob("Bob");

	ScavTrap bobCopy = bob;

	bob.attack("jimbo");
	bob.takeDamage(5);
	bob.beRepaired(2);
	bob.guardGate();

	std::cout << "\n";
	bobCopy.takeDamage(20);
}