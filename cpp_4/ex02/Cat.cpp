/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:26:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:33:56 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : A_Animal("Cat") {
	std::cout << "Cat default constructor called.\n";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : A_Animal(other) {
	std::cout << "Cat copy constructor called.\n";
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called.\n";
	if (this != &other) {
		_brain = other._brain;
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

std::string  Cat::getIdea(int idx) const {
	return _brain->getIdea(idx);
}
