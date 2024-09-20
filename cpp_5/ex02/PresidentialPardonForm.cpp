/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:02:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 11:50:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "[PresPardonForm] default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << "[PresPardonForm] copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresPardonForm] destructor called\n";
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	std::cout << "[PresPardonForm] assignment operator called\n";
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& b) {
	checkRequirement(b);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
