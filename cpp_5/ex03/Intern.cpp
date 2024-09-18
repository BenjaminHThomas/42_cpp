/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:51:03 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/18 12:22:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "[Intern] default constructor called\n";
}

Intern::Intern(const Intern &intern)
{
	(void)intern;
	std::cout << "[Intern] copy constructor called\n";
}

Intern::~Intern()
{
	std::cout << "[Intern] destructor called\n";
}

Intern & Intern::operator=(const Intern &intern)
{
	std::cout << "[Intern] assignment operator called\n";
	(void)intern;
	return *this;
}

class Intern::FormNotFoundException : public std::exception {
	private:
		std::string _errMsg;
	public:
		FormNotFoundException(const std::string& formName)
			: _errMsg("Form: '" + formName + "' is not valid\n") {};
		const char* what() const throw() {
			return _errMsg.c_str();
		}
};

static std::string to_upper(const std::string& in) {
	std::string newName;
	for (int i = 0; i < in.size(); ++i) {
		if (std::isalpha(in[i])) {
			newName += std::toupper(in[i]);
		}
	}
	return newName;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string cleanName = to_upper(formName);
	std::string forms[3] = {"PRESIDENTIALPARDON", "ROBOTOMYREQUEST", "SHRUBBERYCREATION"};
	for (int i = 0; i < 3; ++i) {
		if (cleanName == forms[i] || cleanName == forms[i] + "FORM") {
			switch(i) {
				case 0: return new PresidentialPardonForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new ShrubberyCreationForm(target);
			}
		}
	}
	throw FormNotFoundException(formName);
	return nullptr;
}