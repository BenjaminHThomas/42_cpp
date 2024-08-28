/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:36:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/28 10:57:56 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

void	HumanB::setWeapon(Weapon &weaponType) {
	this->weaponType = &weaponType;
}

void	HumanB::attack() {
	std::cout << this->name << " attacks with their " << this->weaponType->getType() << std::endl;
}
