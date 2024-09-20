/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:16:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 10:40:21 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat bob("Bob", 1);
	Bureaucrat jim;
	jim = bob;

	std::cout << bob;
	try {
		bob.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		bob.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << jim;
	try {
		jim.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	return 0;
}