/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 11:19:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Form] Error: Grade too high\n";
		}
};

class Form::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Form] Error: Grade too low\n";
		}
};

Form::Form() : 
	_name("NoNameForm"), 
	_isSigned(false), 
	_gradeToSign(1), 
	_gradeToExec(1) 
{
	std::cout << "[Form] Default form constructor called\n";
}

Form::Form (std::string name, int gradeToSign, int gradeToExec) : 
	_name(name), 
	_isSigned(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExec(gradeToExec) 
{
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
	std::cout << "[Form] Form constructor called\n";
}

Form::Form(const Form &other) :  
	_name(other._name), 
	_isSigned(false),
	_gradeToSign(other._gradeToSign),
	_gradeToExec(other._gradeToExec)
{
	std::cout << "[Form] Form copy constructor called\n";
}

Form::~Form()
{
	std::cout << "[Form] Default form destructor called\n";
}

Form & Form::operator=(const Form &other)
{
	(void)other;
	std::cout << "[Form] form copy operator called\n";
	return *this;
}

const std::string Form::getName() const {
	return _name;
}

bool Form::getStatus() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExec() const {
	return _gradeToExec;
}

std::ostream& operator<<(std::ostream& o, const Form &f) {
	o << "[Form] Form " << f.getName() << ", needs grade " << f.getGradeToSign() << " to sign, "
	<< "and grade " << f.getGradeToExec() << " to execute. Signed status: " << f.getStatus() << "\n";
	return o;
}

void Form::beSigned(const Bureaucrat& b) {
	if (_isSigned)
	{
		std::cout << getName() << " is form is already signed!\n";
		return ;
	}
	if (b.getGrade() > _gradeToSign) {
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}