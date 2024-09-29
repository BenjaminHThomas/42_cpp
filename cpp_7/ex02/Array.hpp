/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:46:59 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/29 14:45:21 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdint.h>

template <class T>
class Array
{
	public:
		T _arr;
		uint32_t _size;

	public:
		uint32_t size(void) const;
		T& operator[](uint32_t index);

	public:
		Array (void);
		Array (uint32_t n);
		Array (const Array &other);
		~Array ();
		Array & operator=(const Array &other);
};

#endif /* ARRAY_HPP */
