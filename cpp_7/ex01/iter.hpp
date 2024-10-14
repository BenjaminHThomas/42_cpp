/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:47:19 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/14 10:57:00 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T *arr, int len, void (*func)(F&)) {
	for (int i = 0; i < len; ++i) {
		func(arr[i]);
	}
}