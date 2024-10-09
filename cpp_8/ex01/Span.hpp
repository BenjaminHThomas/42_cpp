/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:40:43 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/09 16:30:48 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

class Span
{
	private:
		std::vector<int> _nums;
		std::vector<int> _sortedNums;
		const u_int32_t	_maxSize;
		bool _numsSorted;

	private:
		void sortNums(void);
		static int compare(const void* a, const void* b);

	public:
		Span ();
		Span (u_int32_t N);
		Span (const Span &other);
		~Span ();
		Span & operator=(const Span &other);

	public:
		class spanFullException;
		class spanEmptyException;

	public:
		u_int32_t getMaxSize(void) const;
		void addNumber(int n);
		void deleteNumber(u_int32_t index);
		int shortestSpan(void);
		int longestSpan(void);
		u_int32_t getSpanSize(void) const;
		void debugPrint(void);
		void addVector(const std::vector<int> & vec);
};

#endif /* SPAN_HPP */
