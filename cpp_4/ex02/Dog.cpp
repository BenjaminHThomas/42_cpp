/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:41:45 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/06 13:24:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : A_Animal("Dog") {
	std::cout << "Dog default constructor called.\n";
	_brain = new Brain;
}

Dog::Dog(std::string _type) : A_Animal(_type) {
	std::cout << "Dog constructor called.\n";
	_brain = new Brain;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor called.\n";
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called.\n";
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
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

std::string  Dog::getIdea(int idx) const {
	if (idx < 0 || idx >= 100) {
		return NULL;
	}
	return _brain->getIdeas()[idx];
}