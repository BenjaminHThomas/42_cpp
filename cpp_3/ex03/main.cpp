/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:36:51 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:49:51 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap diego("Diego");

	std::cout << "HP: " << diego.getHitPoints() << "\n";
	std::cout << "EP: " << diego.getEnergyPoints() << "\n";
	std::cout << "AD: " << diego.getAttackDamage() << "\n";
	diego.attack("old bob");
	diego.guardGate();
	diego.highFivesGuys();
	diego.whoAmI();
}
