/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 17:34:57 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const std::string _target;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;
protected:
public:
	AForm ();
	AForm (std::string name, std::string target, int gradeToSign, int gradeToExec);
	AForm (const AForm &other);
	virtual ~AForm ();
	AForm & operator=(const AForm &other);
	const std::string getName() const;
	const std::string getTarget() const;
	bool getStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	class GradeTooHighException;
	class GradeTooLowException;
	class FormUnsignedException;
	virtual void beSigned (const Bureaucrat& b);
	virtual void execute (const Bureaucrat& b) = 0;
	bool checkRequirement(const Bureaucrat& b) const;
	// void setName(std::string name);
	// void setTarget(std::string target);
};

std::ostream& operator<<(std::ostream& o, const AForm &f);

#endif /* FORM_HPP */
