/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:39:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 10:06:48 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->name = name;
	this->hitPoints = defaultHitPoints;
	this->maxHealth = defaultHitPoints;
	this->energyPoints = defaultEnergyPoints;
	this->attackDamage = defaultAttackDamage;
	std::cout << "FragTrap constructor called.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = defaultHitPoints;
	this->maxHealth = defaultHitPoints;
	this->energyPoints = defaultEnergyPoints;
	this->attackDamage = defaultAttackDamage;
	std::cout << "FragTrap constructor called.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called.\n";
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called.\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << name << " would really like a high five...\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assign operator called.\n";
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}
