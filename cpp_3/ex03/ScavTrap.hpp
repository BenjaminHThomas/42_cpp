/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:52:43 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:36:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		//
	protected:
		static unsigned int const defaultHitPoints = 100;
		static unsigned int const defaultEnergyPoints = 50;
		static unsigned int const defaultAttackDamage = 20;
		using ClapTrap::maxHealth;
		using ClapTrap::energyPoints;
		using ClapTrap::hitPoints;
		using ClapTrap::attackDamage;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target) override;
};
