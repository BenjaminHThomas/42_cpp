/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:39:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 16:53:56 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hitPoints = 100;
	maxHealth = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << name << " the fragtrap, has been constructed.\n";
}

FragTrap::~FragTrap() {
	std::cout << name << " the fragtrap, has been destructed.\n";
}

void FragTrap::highFivesGuys() {
	std::cout << name << " would really like a high five...\n";
}