/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN(old).cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:06:52 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/21 13:00:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN(old).hpp"

RPN::RPN() :
	_validOps("+-/*"),
	_verbose(false)
{
	
}

void RPN::processChar(char c) {
	if (isspace(c)) {
		return ;
	}
	if (isdigit(c) && !isdigit(_lastToken)) {
		_numList.push_back(c - '0');
		_lastToken = c;
	} else if (_validOps.find(c) != std::string::npos) {
		_opList.push_back(c);
		_lastToken = c;
	} else {
		throw std::runtime_error("Error: invalid char");
	}
}

RPN::RPN(std::string equation, bool verbose) :
	_validOps("+-/*"),
	_verbose(verbose)
{
	if (equation.size() < 5) {
		if (equation.size() == 1 && isdigit(equation[0])) {
			_numList.push_back(equation[0] - '0');
			return ;
		} else {
			throw std::runtime_error("Error: invalid input");
		}
	}
	if (!isdigit(equation[2]) || equation[1] != ' ' || equation[3] != ' ') { // Sorry, this is ugly
		throw std::runtime_error("Error: invalid input");
	}
	_numList.push_back(equation[0] - '0');
	_numList.push_back(equation[2] - '0');
	_lastToken = equation[2];
	for (size_t i = 4; i < equation.size(); ++i) {
		processChar(equation[i]);
	}
	if (_numList.size() != _opList.size() + 1) {
		throw std::runtime_error("Error: invalid size");
	}
}

RPN::RPN(const RPN & other) :
	_validOps("+-/*"),
	_verbose(other._verbose)
{
	_numList = other._numList;
	_opList = other._opList;
}

RPN::~RPN()
{
	
}

RPN & RPN::operator=(const RPN & other)
{
	if (this != &other)
	{
		_numList = other._numList;
		_opList = other._opList;
	}
	return *this;
}

double RPN::calculate(double num1, double num2, char op) const {
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
	case '/':
		if (_verbose)
			std::cout << num1 << " / " << num2 << "\n";
		return num1 / num2;
	case '*':
		if (_verbose)
			std::cout << num1 << " * " << num2 << "\n";
		return num1 * num2;
	default:
		throw std::runtime_error("Error: invalid calc");
		break ;
	}
}

void RPN::debugPrint() const {
	if (!_verbose)
		return ;
	std::list<double>::const_iterator numIt;
	std::list<char>::const_iterator opIt;

	std::cout << "num list: ";
	for (numIt = _numList.begin(); numIt != _numList.end(); ++numIt) {
		std::cout << *numIt << " ";
	}
	std::cout << "\n";

	std::cout << "op list: ";
	for (opIt = _opList.begin(); opIt != _opList.end(); ++opIt) {
		std::cout << *opIt << " ";
	}
	std::cout << "\n";
}

void RPN::execute() const {
	std::list<double>::const_iterator numIt;
	std::list<char>::const_iterator opIt;
	double result = 0;

	if (_numList.size() == 1) {
		std::cout << _numList.front() << "\n";
		return ;
	}
	// execute calculation of first 2 numbers
	numIt = _numList.begin();
	opIt = _opList.begin();
	std::list<double>::const_iterator nextNumIt = numIt;
	++nextNumIt;
	result = calculate(*numIt, *nextNumIt, *opIt);
	numIt = ++nextNumIt;
	++opIt;
	// calculate remaining numbers
	while (numIt != _numList.end()) {
		result = calculate(result, *numIt, *opIt);
		++numIt;
		++opIt;
	}
	std::cout << result << std::endl;
}
