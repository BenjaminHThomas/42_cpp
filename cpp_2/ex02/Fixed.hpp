/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:16:28 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/02 12:31:45 by bthomas          ###   ########.fr       */
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
		static const int intLim = (1 << 23);
		static const int floatLim = (1 << 24);
	public:
		Fixed();
		~Fixed();
		Fixed(int const n);
		Fixed(float const f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		Fixed& min(Fixed& f1, Fixed&f2);
		static const Fixed& min(const Fixed& f1, const Fixed&f2);
		Fixed& max(Fixed& f1, Fixed&f2);
		static const Fixed& max(const Fixed& f1, const Fixed&f2);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream& o, const Fixed &other);
