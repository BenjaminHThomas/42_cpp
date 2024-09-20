/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:24:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 10:45:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;
protected:
public:
	Bureaucrat ();
	Bureaucrat (std::string name, int grade);
	Bureaucrat (const Bureaucrat &bureaucrat);
	~Bureaucrat ();
	Bureaucrat & operator=(const Bureaucrat &bureaucrat);
	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	class GradeTooHighException;
	class GradeTooLowException;
	void signForm (AForm& f);
	void executeForm (AForm& f);
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat &b);

#endif /* BUREAUCRAT_HPP */
