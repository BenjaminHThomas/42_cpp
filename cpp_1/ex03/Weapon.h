/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:13:57 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 15:30:28 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type = "hands") : type(type) {};
		~Weapon() {};
		std::string	getType();
		void	setType(std::string type);
};
