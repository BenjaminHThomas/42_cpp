/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:16:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 14:22:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat bob("Bob", 1);
	Bureaucrat jim;

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