/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:09:16 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 08:31:43 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once
#ifndef ZOMBIE_H

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		std::string	getName();
		void		announce();

	private:
		std::string	name;
};

Zombie*	newZombie(std::string name = "bob");
void	randomChump(std::string name);

#endif // !ZOMBIE_H