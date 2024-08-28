/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:24:08 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 15:49:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon type) {
	this->name = name;
	this->weaponType = type;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weaponType.getType() << std::endl;
}
