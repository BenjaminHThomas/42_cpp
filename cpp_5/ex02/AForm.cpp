/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:23:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 17:52:59 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Form] Error: Grade too high\n";
		}
};

class AForm::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Form] Error: Grade too low\n";
		}
};

class AForm::FormUnsignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Form] Error: Form is not signed\n";
		}
};

AForm::AForm() : 
	_name("NoNameForm"),
	_target("NoNameTarget"),
	_isSigned(false),
	_gradeToSign(1),
	_gradeToExec(1)
{
	std::cout << "[AForm] Default AForm constructor called\n";
}

AForm::AForm (std::string name, std::string target, int gradeToSign, int gradeToExec) : 
	_name(name), 
	_target(target),
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
	std::cout << "[AForm] AForm constructor called\n";
}

AForm::AForm(const AForm &other)
{
	*this = other;
	std::cout << "[AForm] AForm copy constructor called\n";
}

AForm::~AForm()
{
	std::cout << "[AForm] Default AForm destructor called\n";
}

AForm & AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_name = other._name;
		_target = other._target;
		_gradeToSign = other._gradeToSign;
		_gradeToExec = other._gradeToExec;
		_isSigned = other._isSigned;
	}
	std::cout << "[AForm] AForm copy operator called\n";
	return *this;
}

const std::string AForm::getName() const {
	return _name;
}

const std::string AForm::getTarget() const {
	return _target;
}

bool AForm::getStatus() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExec() const {
	return _gradeToExec;
}

std::ostream& operator<<(std::ostream& o, const AForm &f) {
	o << "[" << f.getName() << "] needs grade " << f.getGradeToSign() << " to sign, "
	<< "and grade " << f.getGradeToExec() << " to execute. Signed status: " << f.getStatus() << "\n";
	return o;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (_isSigned)
	{
		std::cout << "[" << _name << "] This form is already signed!\n";
		return ;
	}
	if (b.getGrade() > _gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
}

bool AForm::checkRequirement(const Bureaucrat& b) const {
	if (!_isSigned) {
		throw FormUnsignedException();
	}
	if (b.getGrade() > _gradeToExec) {
		throw GradeTooLowException();
	}
	return true;
}

void AForm::setName(std::string name) {
	_name = name;
}

void AForm::setTarget(std::string target) {
	_target = target;
}