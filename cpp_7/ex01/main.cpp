/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:39:00 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/28 19:43:25 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void test_func1(int &n) {
	n += 1;
}

void test_func2(std::string& s) {
	s += " 42";
}

int main(void){
	int arr1[7] = {1,2,3,4,5,6,7};
	std::string arr2[4] = {"wow", "hello", "goop", "beans"};

	iter(arr1, 7, test_func1);
	for (int i = 0; i < 7; ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << "\n";

	iter(arr2, 4, test_func2);
	for (int i = 0; i < 4; ++i) {
		std::cout << arr2[i] << "\n";
	}
	return 0;
}