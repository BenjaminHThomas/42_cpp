/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:25:36 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 10:45:01 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Bureaucrat] Error: Grade too high.\n";
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "[Bureaucrat] Error: Grade too low.\n";
		}
};

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(MIN_GRADE) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
	std::cout << "[Bureaucrat] bureaucrat constructor called.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	if (this != &other) {
		*this = other;
	}
	std::cout << "[Bureaucrat] " << "bureaucrat copy constructor called.\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] " << "bureaucrat destructor called.\n";
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		//const_cast<std::string&>(_name) = other._name; unsure on this.
		_grade = other._grade;
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
	if (this->_grade == MAX_GRADE) {
		throw GradeTooHighException();
	}
	--_grade;
	std::cout << "[Bureaucrat] " << _name << " has been promoted. Their grade is now " << _grade << "\n";
}

void Bureaucrat::decrementGrade() {
	if (_grade == MIN_GRADE) {
		throw GradeTooLowException();
	}
	++_grade;
	std::cout << "[Bureaucrat] " << _name << " has been demoted. Their grade is now " << _grade << "\n";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << "[Bureaucrat] " << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (o);
}

void Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << "[Bureaucrat] " << _name << " signed " << f.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << "[Bureaucrat] " << _name << " couldn't sign " << f.getName() << " because his grade is too low :(\n";
	}
}

void Bureaucrat::executeForm(AForm& f) {
	try {
		f.execute(*this);
		std::cout << "[Bureaucrat] " << _name << " executed " << f.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}