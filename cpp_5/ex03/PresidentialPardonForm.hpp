/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:02:47 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/17 20:23:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
protected:
public:
	PresidentialPardonForm (std::string target = "NoNameTarget");
	PresidentialPardonForm (const PresidentialPardonForm &other);
	~PresidentialPardonForm ();
	PresidentialPardonForm & operator=(const PresidentialPardonForm &other);
	void execute(const Bureaucrat& b);
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
