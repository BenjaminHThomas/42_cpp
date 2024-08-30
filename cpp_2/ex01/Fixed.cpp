/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:16:50 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/30 10:22:16 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const n) {
	std::cout << "int constructor called\n";
	if (n > this->intLim - 1 || n < -this->intLim) { // outside scope, but I'd like to throw custom exception
		std::cout << "int too big/small\n";
		this->fixed = 0;
		return ;
	}
	this->fixed = n << this->fractBits;
}

Fixed::Fixed(float const f) {
	std::cout << "float constructor called\n";
	if (f > this->floatLim - 1 || f < -this->floatLim) {
		std::cout << "float too big/small\n";
		this->fixed = 0;
		return ;
	}
	this->fixed = f * (1 << fractBits);
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

std::ostream& operator<<(std::ostream& o, const Fixed &other) {
	o << other.toFloat();
	return (o);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed = raw;
}

float Fixed::toFloat() const {
	return ((float)this->fixed / (1 << this->fractBits));
}

int	Fixed::toInt() const {
	return (this->fixed>>Fixed::fractBits);
}

