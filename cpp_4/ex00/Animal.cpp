/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:21:15 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 15:56:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	_type = "NoType";
	std::cout << "Animal default constructor called.\n";
}

Animal::Animal(std::string _type) : _type(_type) {
	std::cout << "Animal constructor called.\n";
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called.\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assignment operator called.\n";
	this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called.\n";
}

void Animal::makeSound() const {
	std::cout << _type << ": Animal sound!\n";
}

std::string Animal::getType() const {
	return _type;
}