/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:06 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/29 10:09:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level) {
	for (std::string::size_type i = 0; i < level.length(); ++i) {
		level[i] = ::toupper(level[i]);
	}
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*arr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			(this->*arr[i])();
			return ;
		}
	}
}

void	Harl::debug() {
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle"
		"-special-ketchup burger. I really do!\n";
}

void	Harl::info() {
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put"
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning() {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for"
	" years whereas you started working here since last month.\n";
}

void	Harl::error() {
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}