/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:16:24 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 17:52:24 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat bob("Bob", 20);
	Form form1("form1", 10, 5);
	Form form2("form2", 150, 100);

	std::cout << "\n";
	std::cout << bob;
	std::cout << form1;

	std::cout << "\n";
	bob.signForm(form1);

	std::cout << "\n";
	bob.signForm(form2);
	return 0;
}