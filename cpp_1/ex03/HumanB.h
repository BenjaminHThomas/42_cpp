/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:27:55 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 15:39:01 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

class HumanB
{
	private:
		std::string	name;
		Weapon		weaponType;
	public:
		HumanB(std::string name) : name(name) {};
		~HumanB() {};
		void	setWeapon(Weapon weaponType);
		Weapon	getWeapon();
		void	attack();
};
