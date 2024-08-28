/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:09:29 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 15:48:43 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weaponType;
	public:
		HumanA(std::string name, Weapon type);
		~HumanA() {};
		void	attack();
};

