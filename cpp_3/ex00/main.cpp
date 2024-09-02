/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:36:51 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/02 14:12:03 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap jimbo("Jimbo");
	ClapTrap sneakyBob("sneaky Bob");
	ClapTrap jimboClone = jimbo;

	sneakyBob.attack(jimbo.getName());
	jimbo.takeDamage(sneakyBob.getAttackDamage());
	jimboClone.beRepaired(10000);

	std::cout << "\n";
	sneakyBob.takeDamage(100000);
	sneakyBob.takeDamage(10);
}