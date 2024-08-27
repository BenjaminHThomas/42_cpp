/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:10:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 08:24:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << getName() << " is deleted.\n";
}

std::string	Zombie::getName() { 
	return (Zombie::name);
}

void	Zombie::announce() {
	std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}
