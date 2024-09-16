/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:25:36 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/16 17:40:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1 || grade > 150) {
		std::cout << "Error: grade " << grade << " is invalid.\n";
		_grade = 150;
	}
	std::cout << "default bureaucrat constructor called.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	if (this != &other) {
		*this = other;
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
		*this = other;
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
	if (this->_grade <= 1) {
		std::cout << "Error: this guy is already the highest rank.\n";
		return ;
	}
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		std::cout << "Error: this guys is already the lowest rank.\n";
		return ;
	}
	++_grade;
}
