/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:56:05 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/17 14:02:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(int ac, char **av) {
	parseInput(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe &other) :
	_unsortedV(other._unsortedV),
	_unsortedD(other._unsortedD)
{
	
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_unsortedD = other._unsortedD;
		_unsortedV = other._unsortedV;
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
	_jacobsNums.push_back(0);
	_jacobsNums.push_back(1);
	while (_jacobsNums.back() < n) {
		int next = _jacobsNums.back() + 2 * _jacobsNums.at(_jacobsNums.size() -2);
		_jacobsNums.push_back(next);
	}
}

template <typename T>
void PmergeMe::printContainer(T & container) {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container.at(i) << " ";
	}
	std::cout << std::endl;
}

// takes either a vector or deque containing int pairs.
template <typename T>
void PmergeMe::mergeContainer(T &container, int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	T L(n1), R(n2);

	for (i = 0; i < n1; ++i) {
		L[i] = container[left + i];
	}
	for (j = 0; j < n2; ++j) {
		R[j] = container[mid + 1 + j];
	}

	i = j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i].first <= R[j].first) {
			container[k++] = L[i++];
		} else {
			container[k++] = R[j++];
		}
	}

	while (i < n1) {
		container[k++] = L[i++];
	}
	while (j < n2) {
		container[k++] = R[j++];
	}
}

template <typename T>
void PmergeMe::mergeSortContainer(T & container, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSortContainer(container, left, mid);
		mergeSortContainer(container, mid + 1, right);
		mergeContainer(container, left, mid, right);
	}
}

template <typename T>
void PmergeMe::recursiveSortContainer(T & pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first < pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
	}
	mergeSortContainer(pairs, 0, pairs.size() - 1);
}

/*
	T is either a vector<int> or deque<int>
	F is either a vector<pair<int, int> > or deque equivalent.
*/
template <typename T, typename F>
T PmergeMe::fjSort(T & unsorted, F & pairs) {
	if (unsorted.size() == 1) {
		return unsorted;
	}
	int straggler = -1;

	// if odd, reserve last number to insert at the end;
	if (unsorted.size() % 2 != 0) {
		straggler = unsorted.back();
		unsorted.pop_back();
	}

	for (size_t i = 0; i < unsorted.size(); i += 2) {
		pairs.push_back(std::make_pair(unsorted[i], unsorted[i + 1]));
	}

	recursiveSortContainer(pairs);
	T smallest;
	T biggest;
	for (size_t i = 0; i < pairs.size(); ++i) {
		smallest.push_back(pairs[i].second);
		biggest.push_back(pairs[i].first);
		//std::cout << "Pair " << i << "(" << pairs[i].first << "," << pairs[i].second << ")\n";
	}

	T inserted(smallest.size(), 0);
	if (smallest.size() >= 2) {
		// insert first smallest
		inserted[0] = 1;
		biggest.insert(std::lower_bound(biggest.begin(), biggest.end(), smallest.front()), smallest.front());
		// use the jacobsthal numbers to fill biggest with numbers from smallest
		for (size_t i = 1; i < _jacobsNums.size() - 1; ++i) {
			int start = _jacobsNums.at(i);
			int end = std::min(static_cast<int>(smallest.size()), _jacobsNums.at(i + 1));
			for (int j = end - 1; j >= start; --j) {
				if (!inserted[j]) {
					biggest.insert(std::lower_bound(biggest.begin(), biggest.end(), smallest.at(j)), smallest.at(j));
					inserted[j] = 1;
				}
			}
		}
	} else {
		biggest.insert(biggest.begin(), smallest.front());
	}
	if (straggler != -1) {
		biggest.insert(std::lower_bound(biggest.begin(), biggest.end(), straggler), straggler);
	}
	return biggest;
}

void PmergeMe::sort() {
	struct timeval vecStart, vecEnd, deqStart, deqEnd;
	std::vector<std::pair<int, int> > pairsV;
	std::deque<std::pair<int, int> > pairsD;
	
	generateJacobsthal(_unsortedD.size() / 2);
	std::cout << "Before:\t";
	printContainer(_unsortedV);

	gettimeofday(&vecStart, NULL);
	std::vector<int> _sortedV = fjSort(_unsortedV, pairsV);
	gettimeofday(&vecEnd, NULL);

	gettimeofday(&deqStart, NULL);
	std::deque<int> _sortedD = fjSort(_unsortedD, pairsD);
	gettimeofday(&deqEnd, NULL);

	std::cout << "After:\t";
	printContainer(_sortedD);

	long double vecDuration = (vecEnd.tv_sec - vecStart.tv_sec) * 1e6 + (vecEnd.tv_usec - vecStart.tv_usec);
	long double deqDuration = (deqEnd.tv_sec - deqStart.tv_sec) * 1e6 + (deqEnd.tv_usec - deqStart.tv_usec);
	std::cout << "Time to process a range of " << _sortedV.size() << " elements with std::vector:\t" << vecDuration << " us\n";
	std::cout << "Time to process a range of " << _sortedD.size() << " elements with std::deque:\t" << deqDuration << " us\n";
}