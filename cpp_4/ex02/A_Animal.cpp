/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:21:15 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 15:56:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal(void) {
	_type = "NoType";
	std::cout << "A_Animal default constructor called.\n";
}

A_Animal::A_Animal(std::string _type) : _type(_type) {
	std::cout << "A_Animal constructor called.\n";
}

A_Animal::A_Animal(const A_Animal& other) {
	std::cout << "A_Animal copy constructor called.\n";
	*this = other;
}

A_Animal& A_Animal::operator=(const A_Animal& other) {
	std::cout << "A_Animal copy assignment operator called.\n";
	this->_type = other._type;
	return *this;
}

A_Animal::~A_Animal() {
	std::cout << "A_Animal destructor called.\n";
}

std::string A_Animal::getType() const {
	return _type;
}