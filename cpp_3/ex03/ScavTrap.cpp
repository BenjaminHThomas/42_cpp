/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:52:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 19:43:31 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called\n";
	this->maxHealth = 100;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called\n";
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate() {
	std::cout << getName() << " is now in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string &target) {
	std::cout << name << " viciously attacks " << target << " causing " << getAttackDamage() << " points of damage.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &value)
{
	std::cout << "ScavTrap assign operator called.\n";
	if (this != &value)
	{
		this->name = value.name;
		this->hitPoints = value.hitPoints;
		this->energyPoints = value.energyPoints;
		this->attackDamage = value.attackDamage;
	}
	return *this;
}
