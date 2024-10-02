/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:26:44 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/02 14:34:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <list>

template <typename T>
int easyfind(T container, int n) {
	int i = 0;
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it, ++i) {
		if (*it == n) {
			return i;
		}
	}
	throw std::out_of_range("Error: int not found in container.\n");
}

#endif /* EASYFIND_HPP */


