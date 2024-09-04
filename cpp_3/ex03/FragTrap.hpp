/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:39:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 10:04:31 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		//
	protected:
		static unsigned int const defaultHitPoints = 100;
		static unsigned int const defaultEnergyPoints = 100;
		static unsigned int const defaultAttackDamage = 30;
		using ClapTrap::attackDamage;
		using ClapTrap::energyPoints;
		using ClapTrap::hitPoints;
		using ClapTrap::maxHealth;
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap & operator=(const FragTrap &value);
		void highFivesGuys(void);
};
