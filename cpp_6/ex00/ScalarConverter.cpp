/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:16:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/21 20:27:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter()
{
	std::cout << "default constructor\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "copy constructor\n";
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "destructor\n";
}

bool ScalarConverter::isInvalidNum(std::string arg) {
	if (arg.empty())
		return true;
	// check for pseudo literals
	if (arg == "-inf" || arg == "+inf" || arg == "nan" ||
		arg == "-inff" || arg == "+inff") {
		return false;
	}
	// check for more than one f
	size_t f_pos = arg.find('f');
	if (f_pos != std::string::npos) {
		if (arg.find('f', f_pos + 1) != std::string::npos)
			return true;
	}
	// check for more than one decimal point
	f_pos = arg.find('.');
	if (f_pos != std::string::npos) {
		if (arg.find('.', f_pos + 1) != std::string::npos)
			return true;
	}
	// check for remaining characters
	for (size_t i = 0 + arg[0] == '-'; i < arg.size(); ++i) {
		if (!isdigit(arg[i]) && arg[i] != '.' && arg[i] != 'f')
			return true;
	}
	return false;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "assignment operator\n";
	return *this;
}

bool ScalarConverter::isInt(std::string arg) {
	int result;
	if (arg.find('.') != std::string::npos || arg.find('f') != std::string::npos)
		return false;
	if (std::istringstream(arg) >> result) {
		outputNormal(result);
		return true;
	}
	return false;
}

bool ScalarConverter::isChar(std::string arg) {
	if (arg.size() == 1 && !isdigit(arg[0])) {
		outputNormal(arg[0]);
		return true;
	}
	return false;
}

bool ScalarConverter::isDouble(std::string arg) {
	double	result;
	if (arg == "-inf" || arg == "+inf" || arg == "nan" ||
		arg == "-inff" || arg == "+inff") {
		outputLiteral(arg);
		return true;
	}
	if (std::istringstream(arg) >> result) {
		outputNormal(result);
		return true;
	}
	return false;
}

void ScalarConverter::convert(std::string arg) {
	if (isChar(arg))
		return ;
	if (isInvalidNum(arg)) {
		outputInvalid();
		return ;
	}
	else if (isInt(arg))
		return ;
	else if (isDouble(arg))
		return ;
	outputInvalid();
}
