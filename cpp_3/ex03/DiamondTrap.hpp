/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:57:50 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 09:41:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{
	private:
		std::string name;
		using ClapTrap::attackDamage;
		using ClapTrap::energyPoints;
		using ClapTrap::hitPoints;
		using ClapTrap::maxHealth;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap &value);
		void whoAmI();
		using ScavTrap::attack;
};
