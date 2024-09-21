/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:16:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/21 16:00:30 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <limits>
#include <string>
#include <stdexcept>
#include <cfloat>

class ScalarConverter
{
private:
	ScalarConverter ();
	ScalarConverter (const ScalarConverter &scalarconverter);
	ScalarConverter & operator=(const ScalarConverter &scalarconverter);
	static bool isInt(std::string arg);
	static bool isChar(std::string arg);
	static void Double(std::string arg);
	static bool isInvalidNum(std::string arg);
	template <typename T>
	static void outputNormal(T val);
	static void outputInvalid();
	static void outputLiteral(std::string val);
public:
	static void convert(std::string arg);
	virtual ~ScalarConverter () = 0;
};

#endif /* SCALARCONVERTER_HPP */
