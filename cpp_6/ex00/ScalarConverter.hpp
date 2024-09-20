/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:16:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 16:04:27 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter ();
	ScalarConverter (const ScalarConverter &scalarconverter);
	ScalarConverter & operator=(const ScalarConverter &scalarconverter);
	static bool isInt(std::string arg);
	static bool isChar(std::string arg);
	static bool isFloat(std::string arg);
	static bool isDouble(std::string arg);
	static bool isInvalidNum(std::string arg);
public:
	static void convert(std::string arg);
	virtual ~ScalarConverter () = 0;
};

#endif /* SCALARCONVERTER_HPP */
