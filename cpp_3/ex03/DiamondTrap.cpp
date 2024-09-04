/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:58:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 09:57:54 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(){
	this->hitPoints = FragTrap::defaultHitPoints;
	this->maxHealth = FragTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap constructor called.\n";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name){
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::defaultHitPoints;
	this->maxHealth = FragTrap::defaultHitPoints;
	this->energyPoints = ScavTrap::defaultEnergyPoints;
	this->attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "DiamondTrap constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap copy constructor called.\n";
	if (this != &other) {
		ClapTrap::name = other.name +  "_clap_name";;
		*this = other;
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
