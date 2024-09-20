/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:00:04 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/20 16:18:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
    char c = 0;
    std::string cs;

    cs += c;
    ScalarConverter::convert("42.065f");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("z");
    ScalarConverter::convert("2147483647");
    ScalarConverter::convert("123AAAA");
    ScalarConverter::convert(cs);
    return 0;
}
