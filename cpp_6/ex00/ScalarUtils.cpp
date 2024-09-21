/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:20:44 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/21 20:01:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

template void ScalarConverter::outputNormal<int>(int);
template void ScalarConverter::outputNormal<char>(char);
template void ScalarConverter::outputNormal<float>(float);
template void ScalarConverter::outputNormal<double>(double);

template <typename T>
void ScalarConverter::outputNormal(T val) {
	char c = static_cast<char>(val);
	int i = static_cast<int>(val);
	double d = static_cast<double>(val);
	std::cout << "Char:\t ";
	if (isprint(c)) {
		std::cout << c << "\n";
	} else {
		std::cout << "unprintable\n";
	}
	if (static_cast<long long>(val) > std::numeric_limits<int>::max() ||
		static_cast<long long>(val) < std::numeric_limits<int>::min() )
	{
		std::cout << "Int:\t out of range\n"; 
	} else {
		std::cout << "Int:\t " << i << ".00\n";
	}
	std::cout << "Float:\t ";
	if (d > std::numeric_limits<float>::max()) {
		std::cout << "+inff\n";
	} else if (d < static_cast<float>(-std::numeric_limits<float>::max())) {
		std::cout << "-inff\n";
	} else {
		std::cout << std::fixed << std::setprecision(2) << d << "f\n";
	}
	std::cout << std::fixed << std::setprecision(2) << "Double:\t " << d << "\n";;
}

void ScalarConverter::outputInvalid(){
	std::cout << "Char:\t" << " impossible\n";
	std::cout << "Int:\t"  << " impossible\n";
	std::cout << "Float:\t" << " impossible\n";
	std::cout << "Double:\t" << " impossible\n";
}

void ScalarConverter::outputLiteral(std::string val) {
	std::cout << "Char:\t" << " impossible\n";
	std::cout << "Int:\t"  << " impossible\n";
	if (val == "-inff" || val == "-inf") {
		std::cout << "Float:\t" << " -inff\n";
		std::cout << "Double:\t" << " -inf\n";
	} else if (val == "+inff" || val == "+inf") {
		std::cout << "Float:\t" << " +inff\n";
		std::cout << "Double:\t" << " +inf\n";
	} else {
		std::cout << "Float:\t" << " impossible\n";
		std::cout << "Double:\t" << " nan\n";
	}
}
