/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:29:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/10 10:56:22 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>
#include <string>

int	main(int ac, char **av) {
	int	N;

	if (ac < 2)
		return (1);
	std::istringstream(av[1]) >> N;
	Zombie* horde = zombieHorde(N, "Bob");
	if (!horde)
		return (1);
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
