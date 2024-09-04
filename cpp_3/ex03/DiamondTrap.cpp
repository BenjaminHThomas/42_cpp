/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:58:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 19:45:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
		ClapTrap(name + "_clap_name"), 
		ScavTrap(name + "_clap_name"), 
		FragTrap(name + "_clap_name") {
	this->name = name;
	this->hitPoints = FragTrap::getHitPoints();
	this->maxHealth = FragTrap::getHitPoints();
	this->energyPoints = ScavTrap::getEnergyPoints();
	this->attackDamage = FragTrap::getAttackDamage();
	std::cout << "DiamondTrap constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap copy constructor called.\n";
	if (this != &other) {
		ClapTrap::name = other.name +  "_clap_name";;
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap assignement operator called.\n";
	if (this != &other)
	{
		ClapTrap::name = other.name +  "_clap_name";
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called.\n";
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->name << " otherwise known as " << ClapTrap::name << ".\n";
}
