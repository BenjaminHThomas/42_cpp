/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:09:16 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 15:11:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

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
