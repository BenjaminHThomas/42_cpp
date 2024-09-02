/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:30:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/02 20:44:45 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called.\n";
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called.\n";
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	this->name = other.name;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor called.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Assign operator constructor called.\n";
	if (this != &other) {
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		this->name = other.name;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0) {
		std::cout << name << " has insufficient energy to attack.\n";
		return ;
	}
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
	--this->energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "Stop it, " << name << " is already dead.\n";
		return ;
	}
	if (hitPoints <= amount) {
		amount = hitPoints;
		hitPoints = 0;
	}
	else {
		hitPoints -= amount;
	}
	std::cout << name << " was hit for " << amount << ". Leaving them at " << hitPoints << "hp.\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0) {
		std::cout << name << " has insufficient energy to be repaired.\n";
		return ;
	}
	if (hitPoints == 10) {
		std::cout << name << " is already at full health, stupid.\n";
		return ;
	}
	if (hitPoints + amount >= 10) {
		amount = 10 - hitPoints;
		hitPoints = 10;
	}
	else {
		hitPoints += amount;
	}
	--energyPoints;
	std::cout << name << " has been repaired for " << amount << " hitpoints. Leaving them at " << hitPoints << "hp.\n";
}

const std::string ClapTrap::getName() {
	return this->name;
}

unsigned int ClapTrap::getAttackDamage() {
	return this->attackDamage;
}
