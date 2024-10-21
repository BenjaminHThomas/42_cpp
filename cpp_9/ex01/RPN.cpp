/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:12:06 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/21 14:28:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string & av1, bool verbose) : 
	_verbose(verbose),
	_av1(av1)
{
	validateInput();
}

RPN::RPN() :
	_verbose(false)
{
}

RPN::RPN(const RPN &other)
{
	_numStack = other._numStack;
	_verbose = other._verbose;
	_av1 = other._av1;
	validateInput();
}

RPN::~RPN()
{
	
}

RPN & RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_numStack = other._numStack;
		_verbose = other._verbose;
		_av1 = other._av1;
	}
	validateInput();
	return *this;
}

void RPN::validateInput(void) const {
	for (size_t i = 0; i < _av1.size(); ++i) {
		if (isspace(_av1[i]))
			continue ;
		if (!isOp(_av1[i]) && !isdigit(_av1[i]))
			throw std::runtime_error("Error: invalid input\n");
	}
}

bool RPN::isOp(char c) const {
	switch (c)
	{
	case '+':
		return true;
	case '-':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	default:
		return false;
	}
}

double RPN::doCalc(char op, double num1, double num2) const {
	switch (op)
	{
	case '+':
		if (_verbose)
			std::cout << num1 << " + " << num2 << "\n";
		return num1 + num2;
	case '-':
		if (_verbose)
			std::cout << num1 << " - " << num2 << "\n";
		return num1 - num2;
	case '*':
		if (_verbose)
			std::cout << num1 << " * " << num2 << "\n";
		return num1 * num2;
	case '/':
		if (_verbose)
			std::cout << num1 << " / " << num2 << "\n";
		return num1 / num2;
	default:
		throw std::runtime_error("Error: invalid operation.\n");
	}
}

double RPN::strToDbl(std::string s) const {
	double result;
	std::stringstream ss(s);
	ss >> result;
	if (ss.fail()) {
		throw std::runtime_error("Error: invalid input\n");
	}
	return result;
}

void RPN::evalRPN(void) {
	std::string buff;
	std::stringstream ss(_av1);
	double result = 0;

	if (_av1.empty())
		return ;
	while (ss >> buff) {
		if (buff.size() == 1 && isOp(buff[0])) {
			if (_numStack.size() < 2) {
				throw std::runtime_error("Error: invalid input\n");
			}
			double num1 = _numStack.top(); _numStack.pop();
			double num2 = _numStack.top(); _numStack.pop();
			char op = buff[0];
			result = doCalc(op, num1, num2);
			_numStack.push(result);
		} else {
			_numStack.push(strToDbl(buff));
		}
	}
	if (_numStack.size() > 1) {
		throw std::runtime_error("Error: invalid input\n");
	}
	std::cout << _numStack.top() << std::endl;
}