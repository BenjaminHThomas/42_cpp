/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:26:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* garfield = new Cat();
	const Animal* baxter = new Dog();
	const WrongAnimal* wrongMeta = new WrongCat();
	const WrongCat* evilGarfield = new WrongCat();

	std::cout << "\n";
	meta->makeSound();
	baxter->makeSound();
	garfield->makeSound();
	wrongMeta->makeSound();
	evilGarfield->makeSound();
	std::cout << "\n";

	delete meta;
	delete baxter;
	delete garfield;
	delete wrongMeta;
	delete evilGarfield;
	return 0;
}