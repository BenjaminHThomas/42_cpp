/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:39:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:46:13 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->hitPoints = 100;
	this->maxHealth = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << name << " the fragtrap, has been constructed.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->maxHealth = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << name << " the fragtrap, has been constructed.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << name << " the fragtrap, has been constructed.\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << name << " the fragtrap, has been constructed.\n";
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->maxHealth = other.maxHealth;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << name << " the fragtrap, has been destructed.\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << name << " would really like a high five...\n";
}