/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:41:45 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 17:57:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called.\n";
	_brain = new Brain;
}

Dog::Dog(std::string _type) : Animal(_type) {
	std::cout << "Dog constructor called.\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called.\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called.\n";
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called.\n";
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << _type << ": Woof!\n";
}

std::string Dog::getType() const {
	return _type;
}