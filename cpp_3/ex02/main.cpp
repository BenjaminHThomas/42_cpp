/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:36:51 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:42:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	FragTrap phil("Phil");
	FragTrap phil2 = phil;

	phil2.attack("bob");
	phil2.takeDamage(95);
	phil2.beRepaired(120);
	phil2.highFivesGuys();
}