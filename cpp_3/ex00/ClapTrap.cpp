/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:30:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:30:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hitPoints(10), maxHealth(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Constructor called.\n";
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called.\n";
	if (this != &other) {
		*this = other;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor called.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Assign operator constructor called.\n";
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0) {
		std::cout << getName() << " has insufficient energy to attack.\n";
		return ;
	}
	std::cout << getName() << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
	--this->energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "Stop it, " << getName() << " is already dead.\n";
		return ;
	}
	if (hitPoints <= amount) {
		amount = hitPoints;
		hitPoints = 0;
	}
	else {
		hitPoints -= amount;
	}
	std::cout << getName() << " was hit for " << amount << ". Leaving them at " << hitPoints << "hp.\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0) {
		std::cout << getName() << " has insufficient energy to be repaired.\n";
		return ;
	}
	if (hitPoints == 10) {
		std::cout << getName() << " is already at full health, stupid.\n";
		return ;
	}
	if (hitPoints + amount > maxHealth) {
		amount = maxHealth - hitPoints;
		hitPoints = maxHealth;
	}
	else {
		hitPoints += amount;
	}
	--energyPoints;
	std::cout << getName() << " has been repaired for " << amount << " hitpoints. Leaving them at " << hitPoints << "hp.\n";
}

const std::string ClapTrap::getName() {
	return name.length()? name : "no_name";
}

unsigned int ClapTrap::getAttackDamage() {
	return this->attackDamage;
}
