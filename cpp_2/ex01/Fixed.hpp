/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:16:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/29 17:38:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed;
		static const int fractBits = 8;
	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		Fixed& operator<<(const Fixed& other);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};


