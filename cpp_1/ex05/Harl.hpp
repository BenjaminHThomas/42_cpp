/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:16 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/29 10:06:54 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <map>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl() {};
		~Harl() {};
		void complain(std::string level);
};

