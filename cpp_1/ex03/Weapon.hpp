/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:13:57 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/11 10:43:58 by bthomas          ###   ########.fr       */
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
		const std::string& getType();
		void	setType(std::string type);
};
