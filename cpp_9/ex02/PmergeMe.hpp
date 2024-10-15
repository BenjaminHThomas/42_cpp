/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:11 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/15 17:23:38 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cstdlib>

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> > _unsortedNums;
		std::vector<int> _sortedNums;
		std::vector<int> _jacobsthalNums;

	private:
		void validateInput(int ac, char **av);
		void generateJacobsthal(int n);
		std::vector<int>::iterator binarySearch(int n, int low, int high);
		void printVec();

	public:
		void sort();

	public:
		PmergeMe ();
		PmergeMe (int ac, char **av);
		PmergeMe (const PmergeMe &other);
		~PmergeMe ();
		PmergeMe & operator=(const PmergeMe &other);
};

#endif /* PMERGEME_HPP */
