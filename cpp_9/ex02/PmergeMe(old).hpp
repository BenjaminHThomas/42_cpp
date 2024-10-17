/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:11 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/15 19:08:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <limits>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> _sortedNumsVec;
		std::vector<std::pair<int, int> > _unsortedNumsVec;
		std::vector<int> _jacobsthalNumsVec;

	private:
		std::deque<int> _sortedNumsDeq;
		std::deque<std::pair<int, int> > _unsortedNumsDeq;
		std::deque<int> _jacobsthalNumsDeq;

	private:
		void printBefore(int ac, char **av);
		void validateInput(int ac, char **av);
		void generateJacobsthal(int n);
		template <typename T>
		typename T::iterator binarySearch(int n, int low, int high, T & container);
		template <typename T>
		void printContainer(T & container);
		template <typename T, typename F>
		void sort(T & sorted, F & unsorted, T & jacobs);

	public:
		void sortBoth();

	public:
		PmergeMe ();
		PmergeMe (int ac, char **av);
		PmergeMe (const PmergeMe &other);
		~PmergeMe ();
		PmergeMe & operator=(const PmergeMe &other);
};

#endif /* PMERGEME_HPP */
