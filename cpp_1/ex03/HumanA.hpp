/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:09:29 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 10:58:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

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

