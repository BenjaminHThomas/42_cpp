/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 13:10:35 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define NUM_ANIMALS 8

int main() {
	// A_Animal* notAllowed = new A_Animal();
	// notAllowed->makeSound();

	Cat* allowed = new Cat();
	Cat cat2;

	cat2 = *allowed;
	std::cout << "\n";
	allowed->makeSound();
	cat2.makeSound();
	std::cout << allowed->getIdea(0) << std::endl;
	std::cout << "\n";
	delete allowed;
	return 0;
}
