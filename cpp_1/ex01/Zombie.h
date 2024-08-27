/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:09:16 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 14:33:35 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once
#ifndef ZOMBIE_H

class Zombie {
	public:
		Zombie() : name("DefaultZombie") {};
		Zombie(std::string name);
		~Zombie();
		std::string	getName();
		void		announce();
		void		changeName(std::string name);

	private:
		std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif // !ZOMBIE_H