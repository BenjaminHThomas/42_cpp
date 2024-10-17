/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:55:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/17 13:41:57 by bthomas          ###   ########.fr       */
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
#include <sys/time.h>
#include <cmath>

class PmergeMe
{
private:
	std::vector<int> _jacobsNums;
	std::vector<int> _unsortedV;
	std::deque<int> _unsortedD;

private:
	template <typename T>
	void printContainer(T & container);
	template <typename T>
	void recursiveSortContainer(T &container);
	template <typename T>
	void mergeSortContainer(T &container, int left, int right);
	template <typename T>
	void mergeContainer(T &container, int left, int mid, int right);
	template <typename T, typename F>
	T fjSort(T & unsorted, F & pairs);

private:
	void parseInput(int ac, char **av);
	void validateInput (int ac, char **av);
	void generateJacobsthal(int n);

public:
	void sort();
	PmergeMe ();
	PmergeMe (int ac, char **av);
	PmergeMe (const PmergeMe &other);
	~PmergeMe ();
	PmergeMe & operator=(const PmergeMe &other);
};

#endif /* PMERGEME_HPP */
