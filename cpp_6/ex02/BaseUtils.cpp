/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:13:48 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/22 17:46:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseUtils.hpp"
#include "A.hpp"
#include <exception>

// randomly instanciates A, B or C and returns the instance as a Base pointer.
Base * generate(void) {
	std::srand(time(0));
	int rand = std::rand() % 3;
	switch (rand) {
		case 0: return (new A());
		case 1: return (new B());	
		default: return (new C());
	}
}

// Prints the actual type of the object pointed to by p: "A", "B" or "C"
void identify(Base* p) {
	if (dynamic_cast<A*>(p) == p) {
		std::cout << "A\n";
	} else if (dynamic_cast<B*>(p) == p) {
		std::cout << "B\n";
	} else if (dynamic_cast<C*>(p) == p) {
		std::cout << "C\n";
	}
}

// Prints the actual type of the object pointed to by p: "A", "B" or "C".
// Using a pointer inside this function is forbidden
void identify(Base& p) {
	try {
		p = dynamic_cast<A&>(p);
		std::cout << "A\n";	
	} catch (std::exception &e) {
		try {
			p = dynamic_cast<B&>(p);
			std::cout << "B\n";
		} catch (std::exception &e) {
			std::cout << "C\n";
		}
	}
}
