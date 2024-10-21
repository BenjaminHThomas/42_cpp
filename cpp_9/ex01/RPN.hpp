/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:01:30 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/21 14:24:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::stack<double> _numStack;
		bool _verbose;
		std::string _av1;

	private:
		bool isOp(char c) const;
		double doCalc(char op, double num1, double num2) const;
		double strToDbl(std::string s) const;
		void validateInput(void) const;
		
	public:
		void evalRPN(void);
		RPN (std::string & av1, bool verbose = false);
		RPN ();
		RPN (const RPN &other);
		RPN & operator=(const RPN &other);
		~RPN ();
};

#endif /* RPN_HPP */
