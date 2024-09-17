/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:25:36 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 14:16:57 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: Grade too high.\n";
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: Grade too low.\n";
		}
};

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade = grade;
	std::cout << "default bureaucrat constructor called.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	if (this != &other) {
		_grade = other.getGrade();
	}
	std::cout << "bureaucrat copy constructor called.\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "bureaucrat destructor called.\n";
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other.getGrade();
	}
	return *this;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const std::string Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1) {
		throw GradeTooHighException();
	}
	--_grade;
	std::cout << _name << " has been promoted. Their grade is now " << _grade << "\n";
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150) {
		throw GradeTooLowException();
	}
	++_grade;
	std::cout << _name << " has been demoted. Their grade is now " << _grade << "\n";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (o);
}