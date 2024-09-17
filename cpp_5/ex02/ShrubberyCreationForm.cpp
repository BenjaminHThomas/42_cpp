/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:04:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 20:34:58 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "[ShrubForm] default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "[ShrubForm] copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubForm] destructor called\n";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other) {
		setName(other.getName());
		setTarget(other.getTarget());
	}
	std::cout << "[ShrubForm] assignment operator called\n";
	return *this;
}
