/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:03:07 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/18 10:34:43 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
protected:
public:
	ShrubberyCreationForm (std::string target = "NoNameTarget");
	ShrubberyCreationForm (const ShrubberyCreationForm &other);
	~ShrubberyCreationForm ();
	ShrubberyCreationForm & operator=(const ShrubberyCreationForm &other);
	void execute(const Bureaucrat& b);
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
