/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:56:05 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/16 15:31:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(int ac, char **av) {
	parseInput(ac, av);
	std::cout << "Before: ";
	printContainer(_unsortedV);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		// Copy data members from pmergeme to this object
	}
	return *this;
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

void PmergeMe::parseInput(int ac, char **av) {
	validateInput(ac, av);
	for (int i = 1; i < ac; ++i) {
		char *endptr;
		long num = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || num > __INT_MAX__) {
			throw std::overflow_error("Error: value is greater than the max int.\n");
		}
		_unsortedV.push_back(static_cast<int>(num));
		_unsortedD.push_back(static_cast<int>(num));
	}
}

void PmergeMe::generateJacobsthal(int n) {
	_jacobsthalNumsVec.push_back(0);
	_jacobsthalNumsVec.push_back(1);
	while (_jacobsthalNumsVec.back() < n) {
		int next = _jacobsthalNumsVec.back() + 2 * _jacobsthalNumsVec.at(_jacobsthalNumsVec.size() -2);
		_jacobsthalNumsVec.push_back(next);
	}
	_jacobsthalNumsDeq = std::deque<int>(_jacobsthalNumsVec.begin(), _jacobsthalNumsVec.end());
}

template <typename T>
void PmergeMe::printContainer(T & container) {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container.at(i) << " ";
	}
	std::cout << std::endl;
} 