/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:16:50 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/29 18:05:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n) {
	int	lim = (1 << 23);
	if (n > lim - 1 || n < -lim) { // need to think of a more elegant solution
		std::cout << "int too big/small\n";
		this->fixed = 0;
		return ;
	}
	this->fixed = n << this->fractBits;
	std::cout << "int constructor called\n";
}

Fixed::Fixed(float const f) {
	if (f > (1 << 24) - 1 || f < -(1 << 24)) {
		std::cout << "float too big/small\n";
		this->fixed = 0;
		return ;
	}
	this->fixed = f * 256;
	std::cout << "float constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Default destructor called\n";
}

Fixed::Fixed(const Fixed& other) : fixed(other.fixed) {
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "copy assignment operator overload called\n";
	if (this != &other) {
		this->fixed = other.fixed;
	}
	return (*this);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed = raw;
}
