/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:41:45 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:28:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called.\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called.\n";
	_brain = other._brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called.\n";
	if (this != &other) {
		_brain = other._brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called.\n";
}

void Dog::makeSound() const {
	std::cout << _type << ": Woof!\n";
}


