/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:00:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/28 19:46:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void swap(T &val1, T &val2) {
	T temp;
	temp = val1;
	val1 = val2;
	val2 = temp;
}

template <typename T>
T min(const T &val1, const T &val2) {
	if (val1 < val2) {
		return val1;
	}
	return val2;
}

template <typename T>
T max(const T &val1, const T &val2) {
	if (val1 > val2) {
		return val1;
	}
	return val2;
}
