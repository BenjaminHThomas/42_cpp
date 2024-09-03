/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:52:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 11:02:15 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called\n";
	maxHealth = 100;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate() {
	std::cout << getName() << " is now in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string &target) {
	std::cout << name << " viciously attacks " << target << " causing " << attackDamage << " points of damage.\n";
}
