/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:00:45 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 17:09:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called.\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called.\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat copy assignment operator called.\n";
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called.\n";
}

void WrongCat::makeSound() const {
	std::cout << _type << ": WrongCat sound!\n";
}

