/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 17:55:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define NUM_ANIMALS 8

int main() {
	Animal **all = new Animal*[NUM_ANIMALS];

	for (size_t i = 0; i < NUM_ANIMALS / 2; ++i) {
		all[i] = new Cat();
	}
	for (size_t i = NUM_ANIMALS / 2; i < NUM_ANIMALS; ++i) {
		all[i] = new Dog();
	}

	std::cout << "\n";
	for (size_t i = 0; i < NUM_ANIMALS; ++i) {
		all[i]->makeSound();
	}
	std::cout << "\n";

	for (size_t i = 0; i < NUM_ANIMALS; ++i) {
		delete all[i];
	}
	delete all;

	return 0;
}
