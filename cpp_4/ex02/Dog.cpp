/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:41:45 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:34:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : A_Animal("Dog") {
	std::cout << "Dog default constructor called.\n";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : A_Animal(other) {
	std::cout << "Dog copy constructor called.\n";
	_brain = new Brain(*other._brain);
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
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << _type << ": Woof!\n";
}

std::string  Dog::getIdea(int idx) const {
	return _brain->getIdea(idx);
}