/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:09:29 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/28 10:55:06 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanA
{
	private:
		std::string	name;
		Weapon*		weaponType;
	public:
		HumanA(std::string name, Weapon &type) : name(name), weaponType(&type) {};
		~HumanA() {};
		void	attack();
};

