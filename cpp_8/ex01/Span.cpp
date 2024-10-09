/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:40:50 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/09 16:39:21 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::spanFullException : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: span is full, cannot add int.\n";
		}
};

class Span::spanEmptyException : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: span is empty, cannot perform operation.\n";
		}
};

Span::Span(void) :
	_maxSize(0),
	_numsSorted(false)
{
}

Span::Span(u_int32_t N) :
	_maxSize(N),
	_numsSorted(false)
{
}

Span::Span(const Span &other) :
	_maxSize(other._maxSize),
	_numsSorted(false)
{
	_nums = other._nums;
}

Span::~Span()
{
	
}

Span & Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numsSorted = false;
		u_int32_t i = 0;
		std::vector<int>::const_iterator it;
		for (it = other._nums.begin(); it != other._nums.end() && i < _maxSize; ++it, ++i) {
			_nums.push_back(*it);
		}
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_nums.size() == _maxSize) {
		throw spanFullException();
	}
	_nums.push_back(n);
	_numsSorted = false;
}

void Span::deleteNumber(u_int32_t index) {
	if (_nums.size() >= index) {
		throw spanEmptyException();
	}
	_nums.erase(_nums.begin() + index);
	_numsSorted = false;
}

u_int32_t Span::getSpanSize() const {
	return _nums.size();
}

u_int32_t Span::getMaxSize() const {
	return _maxSize;
}

int Span::compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void Span::sortNums(void) {
	if (_numsSorted || _nums.size() < 2) {
		return ;
	}
	_sortedNums = _nums;
	qsort(&_sortedNums[0], _sortedNums.size(), sizeof(int), compare);
	_numsSorted = true;
}

int Span::shortestSpan(void) {
	if (_nums.size() < 2) {
		throw spanEmptyException();
	}
	int minDiff = __INT_MAX__;
	int diff;
	sortNums();

	std::vector<int>::const_iterator it;
	for (it = _sortedNums.begin() + 1; it < _sortedNums.end(); ++it) {
		diff = *it - *(it - 1);
		if (diff < minDiff) {
			minDiff = diff;
		}
		if (diff == 0) {
			break ;
		}
	}
	return minDiff;
}

int Span::longestSpan(void) {
	if (_nums.size() < 2) {
		throw spanEmptyException();
	}
	sortNums();
	return (_sortedNums.back() - _sortedNums.front());
}

void Span::debugPrint(void) {
	std::vector<int>::const_iterator it;
	for (it = _nums.begin(); it != _nums.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void Span::addVector(const std::vector<int> & vec) {
	if (_nums.size() == _maxSize) {
		throw spanFullException();
	}
	std::vector<int>::const_iterator it;
	u_int32_t i = _nums.size();
	for (it = vec.begin(); it != vec.end() && i <= _maxSize; ++it, ++i) {
		_nums.push_back(*it);
	}
}