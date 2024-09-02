/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:16:50 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/02 12:31:37 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed(0) {
}

Fixed::Fixed(int const n) {
	if (n > this->intLim - 1 || n < -this->intLim) { // outside scope, but I'd like to throw custom exception
		std::cout << "int too big/small\n";
		this->fixed = 0;
		return ;
	}
	this->fixed = n << this->fractBits;
}

Fixed::Fixed(float const f) {
	if (f > this->floatLim - 1 || f < -this->floatLim) {
		std::cout << "float too big/small\n";
		this->fixed = 0;
		return ;
	}
	this->fixed = roundf(f * (1 << fractBits));
}

Fixed::~Fixed() {
};

Fixed::Fixed(const Fixed& other) : fixed(other.fixed) {
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->fixed = other.fixed;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& o, const Fixed &other) {
	return (o << other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const {
	return (this->fixed > other.fixed);
}

bool Fixed::operator<(const Fixed&other) const {
	return (this->fixed < other.fixed);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->fixed >= other.fixed);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->fixed <= other.fixed);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->fixed == other.fixed);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->fixed != other.fixed);
}

Fixed Fixed::operator+(const Fixed &other) {
	Fixed newFixed = *this;
	newFixed.fixed += other.fixed;
	return (newFixed);
}

Fixed Fixed::operator-(const Fixed &other) {
	Fixed newFixed = *this;
	newFixed.fixed -= other.fixed;
	return (newFixed);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed newFixed = *this;
	newFixed.fixed = roundf((float)(newFixed.toFloat() * other.toFloat()) * (1 << fractBits));
	return (newFixed);
}

Fixed Fixed::operator/(const Fixed &other) {
	Fixed newFixed = *this;
	newFixed.fixed = roundf((float)(newFixed.toFloat() / other.toFloat()) * (1 << fractBits));
	return (newFixed);
}

Fixed& Fixed::operator++() {
	this->fixed++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++this->fixed;
	return (temp);
}

Fixed& Fixed::operator--() {
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--this->fixed;
	return (temp);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 > f2 ? f2 : f1);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1 > f2 ? f2 : f1);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 > f2 ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1 > f2 ? f1 : f2);
}

int	Fixed::getRawBits() const {
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed = raw;
}

float Fixed::toFloat() const {
	return ((float)this->fixed / (1 << this->fractBits));
}

int	Fixed::toInt() const {
	return (this->fixed>>Fixed::fractBits);
}

