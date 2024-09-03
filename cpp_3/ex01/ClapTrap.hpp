/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:57:58 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/03 10:40:15 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
		unsigned int maxHealth;
	public:
		ClapTrap(std::string name = "Clap Trap");
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		const std::string getName();
		unsigned int getAttackDamage();
		std::string getName() const;
};

