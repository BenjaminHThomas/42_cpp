/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:02:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 20:24:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
protected:
public:
	RobotomyRequestForm (std::string target = "NoNameTarget");
	RobotomyRequestForm (const RobotomyRequestForm &other);
	~RobotomyRequestForm ();
	RobotomyRequestForm & operator=(const RobotomyRequestForm &other);
	void execute(const Bureaucrat& b);
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
