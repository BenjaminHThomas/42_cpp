/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:04:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 11:45:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "[ShrubForm] default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "[ShrubForm] copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubForm] destructor called\n";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other) {
		setName(other.getName());
		setTarget(other.getTarget());
	}
	std::cout << "[ShrubForm] assignment operator called\n";
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) {
	checkRequirement(b);

	std::string fileContents;
	std::string line;
	std::string f1 = "tree1.txt";
	std::string f2 = "tree2.txt";
	std::ifstream infile1(f1.c_str());
	std::ifstream infile2(f2.c_str());
	if (!infile1 || !infile2) {
		std::cerr << "Error: cannot open tree art files.\n";
		return ;
	}
	while (std::getline(infile1, line)) {
		fileContents += line + "\n";
	}
	fileContents += "\n\n";
	while (std::getline(infile2, line)) {
		fileContents += line + "\n";
	}
	infile1.close();
	infile2.close();
	std::ofstream outFile((getTarget() + "_shrubbery").c_str());
	if (!outFile) {
		std::cerr << "Error: file " << (getTarget() + "_shrubbery") << " cannot be created.\n";
	} else {
		outFile << fileContents;
		outFile.close();
	}
}