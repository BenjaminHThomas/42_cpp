/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:43:56 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/02 14:39:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	{
		std::vector<int> v;
		v.assign(7, 42);
		//v.assign(10, 90);
		try {
			int n = easyfind(v, 42);
			std::cout << n << "\n";
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	{
		std::list<int> l;
		l.push_front(5);
		l.push_front(4);
		l.push_front(3);
		l.push_front(2);
		l.push_front(1);
		try {
			int n = easyfind(l, 4);
			std::cout << n << "\n";
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	return 0;
}