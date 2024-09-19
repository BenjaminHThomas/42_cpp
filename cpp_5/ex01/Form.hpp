/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 11:42:19 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExec;
protected:
public:
	Form ();
	Form (std::string name, int gradeToSign, int gradeToExec);
	Form (const Form &other);
	~Form ();
	Form & operator=(const Form &other);
	const std::string getName() const;
	bool getStatus() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	class GradeTooHighException;
	class GradeTooLowException;
	void beSigned (const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& o, const Form &f);

#endif /* FORM_HPP */
