/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/16 16:01:57 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _jacobsthalNumsVec;
	std::vector<int> _sortedV;
	std::vector<int> _unsortedV;

private:
	std::deque<int> _jacobsthalNumsDeq;
	std::deque<int> _sortedD;
	std::deque<int> _unsortedD;

private:
	void parseInput(int ac, char **av);
	void validateInput (int ac, char **av);
	void generateJacobsthal(int n);
	template <typename T>
	void printContainer(T & container);

public:
	PmergeMe ();
	PmergeMe (int ac, char **av);
	PmergeMe (const PmergeMe &other);
	~PmergeMe ();
	PmergeMe & operator=(const PmergeMe &other);
};

#endif /* PMERGEME_HPP */
