/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:39:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 19:36:45 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->maxHealth = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
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

void FragTrap::highFivesGuys() {
	std::cout << name << " would really like a high five...\n";
}

FragTrap& FragTrap::operator=(const FragTrap &value)
{
	std::cout << "FragTrap assign operator called.\n";
	if (this != &value)
	{
		this->name = value.name;
		this->hitPoints = value.hitPoints;
		this->energyPoints = value.energyPoints;
		this->attackDamage = value.attackDamage;
	}
	return *this;
}