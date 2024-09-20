/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:04:26 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 11:41:33 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "[RobotomyForm] default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "[RobotomyForm] copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyForm] destructor called\n";
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	std::cout << "[RobotomyForm] assignment operator called\n";
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& b) {
	checkRequirement(b);
	std::srand(time(0));
	std::cout << "*brrrrrrrrrrrrrrr* ";
	if (std::rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotomized.\n";
	} else {
		std::cout << getTarget() << " failed to be robotomized.\n";
	}
}
