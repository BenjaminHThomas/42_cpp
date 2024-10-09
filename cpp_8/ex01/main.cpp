/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:58:58 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/09 16:42:33 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

std::vector<int> getBigVector(void) {
	size_t vecSize = 10000;
	std::vector<int> randomInts(vecSize);
	for (size_t i = 0; i < vecSize; ++i) {
		randomInts[i] = rand() % 100;
	}
	return randomInts;
}

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.debugPrint();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::vector<int> bigBoy = getBigVector();
		Span sp2 = Span(10000);
		sp2.addVector(bigBoy);
		//sp2.debugPrint();
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	return 0;
}