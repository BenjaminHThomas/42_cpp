/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:16:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/18 10:45:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat bob("Bob", 20);
	RobotomyRequestForm rf("Bob's mother");
	ShrubberyCreationForm sf("trees");
	PresidentialPardonForm pf("jimbo");

	std::cout << "\n";
	bob.signForm(sf);
	bob.executeForm(sf);
	bob.signForm(rf);
	bob.executeForm(rf);
	bob.signForm(pf);
	bob.executeForm(pf);
	std::cout << "\n";
	return 0;
}