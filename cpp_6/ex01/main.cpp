/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:37:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/22 16:00:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data* d = new Data(16, 32);
	uintptr_t raw;

	std::cout << *d;
	raw = Serializer::serialize(d);
	std::cout << raw << "\n";
	Data *d2 = Serializer::deserialize(raw);
	std::cout << *d2;
	delete d;
	return 0;
}
