/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:52:43 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:27:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	private:
		//
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target) override;
};
