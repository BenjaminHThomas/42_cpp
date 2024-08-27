/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:29:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/27 08:33:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	Zombie* bob = newZombie();
	Zombie*	steve = newZombie("steve");
	randomChump("gilbert");
	bob->announce();
	steve->announce();
	delete bob;
	delete steve;
	return (0);
}
