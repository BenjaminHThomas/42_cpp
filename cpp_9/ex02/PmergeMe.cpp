/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/15 17:39:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

void PmergeMe::validateInput(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		std::string numIn = av[i];
		for (int x = 0; x < static_cast<int>(numIn.size()); ++x) {
			if (!isdigit(numIn[x])) {
				throw std::runtime_error("Error: invalid input\n");
			}
		}
	}
}

void PmergeMe::generateJacobsthal(int n) {
	_jacobsthalNums.push_back(0);
	_jacobsthalNums.push_back(1);
	while (_jacobsthalNums.back() < n) {
		int next = _jacobsthalNums.back() + 2 * _jacobsthalNums.at(_jacobsthalNums.size() -2);
		_jacobsthalNums.push_back(next);
	}
}

PmergeMe::PmergeMe (int ac, char **av) {
	validateInput(ac, av);
	for (int i = 1; i < ac - 1; i += 2) {
		std::pair<int, int> tempPair;
		char *endptr;
		long num1 = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || num1 > __INT_MAX__) {
			throw std::overflow_error("Error: value is greater than max int.\n");
		}
		long num2 = std::strtol(av[i + 1], &endptr, 10);
		if (*endptr != '\0' || num2 > __INT_MAX__) {
			throw std::overflow_error("Error: value is greater than max int.\n");
		}
		if (num1 > num2) {
			tempPair.first = static_cast<int>(num1);
			tempPair.second = static_cast<int>(num2);
		} else {
			tempPair.first = static_cast<int>(num2);
			tempPair.second = static_cast<int>(num1);
		}
		_unsortedNums.push_back(tempPair);
	}
	if ((ac - 1) % 2 != 0) {
		char *endptr;
		long last = std::strtol(av[ac - 1], &endptr, 10);
		if (*endptr != '\0' || last > __INT_MAX__) {
			throw std::overflow_error("Error: value is greater than max int.\n");
		}
		_sortedNums.push_back(static_cast<int>(last));
	}
	generateJacobsthal(ac - 1);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	_unsortedNums = other._unsortedNums;
	_sortedNums = other._sortedNums;
	_jacobsthalNums = other._jacobsthalNums;
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_unsortedNums = other._unsortedNums;
		_sortedNums = other._sortedNums;
		_jacobsthalNums = other._jacobsthalNums;
	}
	return *this;
}

std::vector<int>::iterator PmergeMe::binarySearch(int n, int low, int high) {
	if (_sortedNums.size() == 0)
		return  _sortedNums.begin();
	if (high <= low) {
		return (n > _sortedNums.at(low)) ?  _sortedNums.begin() + (low + 1) :  _sortedNums.begin() + low;
	}
	int mid = (low + high) / 2;
	if (n == _sortedNums.at(mid)) {
		return  _sortedNums.begin() + mid + 1;
	}
	if (n > _sortedNums.at(mid))
		return binarySearch(n, mid + 1, high);
	return binarySearch(n, low, mid - 1);
}

void PmergeMe::sort() {
	// insert sorted large values
	std::vector<std::pair<int, int> >::iterator it_uns;
	for (it_uns = _unsortedNums.begin(); it_uns != _unsortedNums.end(); ++it_uns) {
		std::vector<int>::iterator it_sort = binarySearch(it_uns->first, 0, _sortedNums.size() - 1);
		_sortedNums.insert(it_sort, it_uns->first);
	}

	// insert smaller values
	std::vector<bool> inserted(_unsortedNums.size(), false);
	// Insert first element if it exists
	if (!_unsortedNums.empty()) {
		std::vector<int>::iterator insertPos = binarySearch(_unsortedNums[0].second, 0, _sortedNums.size());
		_sortedNums.insert(insertPos, _unsortedNums[0].second);
		inserted[0] = true;
	}

	// Insert remaining elements according to Jacobsthal sequence
	for (std::vector<int>::iterator it_jacob = _jacobsthalNums.begin() + 1; it_jacob != _jacobsthalNums.end(); ++it_jacob) {
		for (int i = *it_jacob - 1; i > *(it_jacob - 1) - 1; --i) {
			if (i >= 0 && i < static_cast<int>(_unsortedNums.size()) && !inserted[i]) {
				std::vector<int>::iterator insertPos = binarySearch(_unsortedNums[i].second, 0, _sortedNums.size());
				_sortedNums.insert(insertPos, _unsortedNums[i].second);
				inserted[i] = true;
			}
		}
	}

	// Insert remaining small values
	for (size_t i = 0; i < _unsortedNums.size(); ++i) {
		if (!inserted[i]) {
			std::vector<int>::iterator insertPos = binarySearch(_unsortedNums[i].second, 0, _sortedNums.size());
			_sortedNums.insert(insertPos, _unsortedNums[i].second);
		}
	}
	printVec();
}

void PmergeMe::printVec() {
	for (size_t i = 0; i < _sortedNums.size(); ++i) {
		std::cout << _sortedNums[i] << " ";
	}
	std::cout << std::endl;
}