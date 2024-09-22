/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:45:53 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/22 16:01:19 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int x, int y)
{
	_x = x;
	_y = y;
}

Data::Data(const Data &Data)
{
	*this = Data;
}

Data::~Data()
{
}

Data & Data::operator=(const Data &Data)
{
	if (this != &Data)
	{
		_x = Data._x;
		_y = Data._y;
	}
	return *this;
}

int Data::getX() const {
	return _x;
}

int Data::getY() const {
	return _y;
}

std::ostream& operator<<(std::ostream& o, const Data &d) {
	o << "X: " << d.getX() << ", Y: " << d.getY() << "\n";
	return (o);
}
