/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:56:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 10:56:06 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::changeName(std::string name) {
	this->name = name;
}

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].changeName(name);
	return (horde);
}
