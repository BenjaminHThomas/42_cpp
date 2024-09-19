/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:26:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:24:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called.\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called.\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called.\n";
	(void)other;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called.\n";
}

void Cat::makeSound() const {
	std::cout << _type << ": Meow!\n";
}
