/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:16:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 10:50:38 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat bob("bob", 20);
	Intern jim;
	AForm *form;

	std::cout << "\n";
	try {
		form = jim.makeForm("garbage", "bob's dad");
		form->beSigned(bob);
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	try {
		form = jim.makeForm("shrubbery creation", "bilbo");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	
	//bob.signForm(*form);
	//bob.executeForm(*form);
	std::cout << "\n";
	return 0;
}