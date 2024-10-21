/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:06:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/14 15:33:35 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <list>

class RPN
{
	private:
		std::list<double> _numList;
		std::list<char> _opList;
		const std::string _validOps;
		char _lastToken;
		const bool _verbose;

	private:
		void processChar(char c);
		double calculate(double num1, double num2, char op) const;

	public:
		void execute(void) const;
		void debugPrint(void) const;

	public:
		RPN ();
		RPN (std::string equation, bool verbose = false);
		RPN (const RPN & other);
		~RPN ();
		RPN & operator=(const RPN & other);
};

#endif /* RPN_HPP */
