/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:37:18 by bthomas          ###   ########.fr       */
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
	Cat stackCat;

	std::cout << "\n";
	allowed->makeSound();
	std::cout << allowed->getIdea(0) << std::endl;
	std::cout << "\n";
	stackCat.makeSound();
	std::cout << stackCat.getIdea(10) << "\n\n";
	delete allowed;
	return 0;
}
