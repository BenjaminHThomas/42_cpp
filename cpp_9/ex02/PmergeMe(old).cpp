/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe(old).cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/17 13:13:42 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe(old).hpp"

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
	_jacobsthalNumsVec.push_back(0);
	_jacobsthalNumsVec.push_back(1);
	while (_jacobsthalNumsVec.back() < n) {
		int next = _jacobsthalNumsVec.back() + 2 * _jacobsthalNumsVec.at(_jacobsthalNumsVec.size() -2);
		_jacobsthalNumsVec.push_back(next);
	}
}

void PmergeMe::printBefore(int ac, char **av) {
	std::cout << "Before: ";
	for (int i = 1; i < ac; ++i) {
		std::cout << av[i] << " ";
	}
	std::cout << "\n";
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
		_unsortedNumsVec.push_back(tempPair);
	}
	if ((ac - 1) % 2 != 0) {
		char *endptr;
		long last = std::strtol(av[ac - 1], &endptr, 10);
		if (*endptr != '\0' || last > __INT_MAX__) {
			throw std::overflow_error("Error: value is greater than max int.\n");
		}
		_sortedNumsVec.push_back(static_cast<int>(last));
	}
	generateJacobsthal(ac - 1);
	_sortedNumsDeq = std::deque<int>(_sortedNumsVec.begin(), _sortedNumsVec.end());
	_unsortedNumsDeq = std::deque<std::pair<int, int> >(_unsortedNumsVec.begin(), _unsortedNumsVec.end());
	_jacobsthalNumsDeq = std::deque<int>(_jacobsthalNumsVec.begin(), _jacobsthalNumsVec.end());
	printBefore(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	_unsortedNumsVec = other._unsortedNumsVec;
	_sortedNumsVec = other._sortedNumsVec;
	_jacobsthalNumsVec = other._jacobsthalNumsVec;

	_unsortedNumsDeq = other._unsortedNumsDeq;
	_sortedNumsDeq = other._sortedNumsDeq;
	_jacobsthalNumsDeq = other._jacobsthalNumsDeq;
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_unsortedNumsVec = other._unsortedNumsVec;
		_sortedNumsVec = other._sortedNumsVec;
		_jacobsthalNumsVec = other._jacobsthalNumsVec;

		_unsortedNumsDeq = other._unsortedNumsDeq;
		_sortedNumsDeq = other._sortedNumsDeq;
		_jacobsthalNumsDeq = other._jacobsthalNumsDeq;
	}
	return *this;
}

template <typename T>
typename T::iterator PmergeMe::binarySearch(int n, int low, int high, T & container) {
	if (container.size() == 0)
		return  container.begin();
	if (high <= low) {
		return (n > container.at(low)) ?  container.begin() + (low + 1) :  container.begin() + low;
	}
	int mid = (low + high) / 2;
	if (n == container.at(mid)) {
		return  container.begin() + mid + 1;
	}
	if (n > container.at(mid))
		return binarySearch(n, mid + 1, high, container);
	return binarySearch(n, low, mid - 1, container);
}

template <typename T, typename F>
void PmergeMe::sort(T & sorted, F & unsorted, T & jacobs) {
	// insert sorted large values
	typename F::iterator it_uns;
	for (it_uns = unsorted.begin(); it_uns != unsorted.end(); ++it_uns) {
		typename T::iterator it_sort = binarySearch(it_uns->first, 0, sorted.size() - 1, sorted);
		sorted.insert(it_sort, it_uns->first);
	}

	// insert smaller values
	std::vector<bool> inserted(unsorted.size(), false);
	// Insert first element if it exists
	if (!unsorted.empty()) {
		typename T::iterator insertPos = binarySearch(unsorted[0].second, 0, sorted.size(), sorted);
		sorted.insert(insertPos, unsorted[0].second);
		inserted[0] = true;
	}

	// Insert remaining elements according to Jacobsthal sequence
	for (typename T::iterator it_jacob = jacobs.begin() + 1; it_jacob != jacobs.end(); ++it_jacob) {
		for (int i = *it_jacob - 1; i > *(it_jacob - 1) - 1; --i) {
			if (i >= 0 && i < static_cast<int>(unsorted.size()) && !inserted[i]) {
				typename T::iterator insertPos = binarySearch(unsorted[i].second, 0, sorted.size(), sorted);
				sorted.insert(insertPos, unsorted[i].second);
				inserted[i] = true;
			}
		}
	}

	// Insert remaining small values
	for (size_t i = 0; i < unsorted.size(); ++i) {
		if (!inserted.at(i)) {
			typename T::iterator insertPos = binarySearch(unsorted[i].second, 0, sorted.size(), sorted);
			sorted.insert(insertPos, unsorted[i].second);
		}
	}
}

template <typename T>
void PmergeMe::printContainer(T & container) {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortBoth() {
	struct timeval vecStart, vecEnd, deqStart, deqEnd;

	gettimeofday(&vecStart, NULL);
	sort(_sortedNumsVec, _unsortedNumsVec, _jacobsthalNumsVec);
	gettimeofday(&vecEnd, NULL);

	gettimeofday(&deqStart, NULL);
	sort(_sortedNumsDeq, _unsortedNumsDeq, _jacobsthalNumsDeq);
	gettimeofday(&deqEnd, NULL);

	std::cout << "After: ";
	printContainer(_sortedNumsVec);

	long double vecDuration = (vecEnd.tv_sec - vecStart.tv_sec) * 1e6 + (vecEnd.tv_usec - vecStart.tv_usec);
	long double deqDuration = (deqEnd.tv_sec - deqStart.tv_sec) * 1e6 + (deqEnd.tv_usec - deqStart.tv_usec);

	std::cout << "Time to process a range of " << _sortedNumsVec.size() << " elements with std::vector: " << vecDuration << " us\n";
	std::cout << "Time to process a range of " << _sortedNumsDeq.size() << " elements with std::deque: " << deqDuration << " us\n";
}