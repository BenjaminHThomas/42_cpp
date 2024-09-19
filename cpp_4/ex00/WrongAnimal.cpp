/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:02:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 11:38:05 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	_type = other._type;
	std::cout << "WrongAnimal copy constructor called.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy assignment operator called.\n";
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called.\n";
}

void WrongAnimal::makeSound() const {
	std::cout << _type << ": WrongAnimal sound!\n";
}

std::string WrongAnimal::getType() const {
	return _type;
}
