/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:12 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:39:21 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	ICharacter* hoarder = new Character("hoarder");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	you->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	for (int i=0; i < 10; i++)
		hoarder->equip(tmp);
	me->unequip(1);

	ICharacter* bob = new Character("bob");

	bob->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(500, *bob);
	std::cout << "Bob time" << std::endl;
	bob->use(0, *me);
	
	delete bob;
	delete me;
	delete src;
	delete you;
	delete hoarder;
	//delete tmp;
}