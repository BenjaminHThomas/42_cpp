/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:26:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/06 12:48:19 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called.\n";
	_brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called.\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called.\n";
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called.\n";
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << _type << ": Meow!\n";
}

std::string Cat::getType() const {
	return _type;
}
