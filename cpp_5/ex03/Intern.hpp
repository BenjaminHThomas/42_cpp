/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:50:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/18 12:07:43 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
private:
protected:
public:
	Intern ();
	Intern (const Intern &intern);
	~Intern ();
	Intern & operator=(const Intern &intern);
	AForm* makeForm(std::string formName, std::string target);
	class FormNotFoundException;
};

#endif /* INTERN_HPP */
