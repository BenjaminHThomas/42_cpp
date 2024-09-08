/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:18:08 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/08 16:44:35 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
}

AMateria::AMateria(std::string const& type) : _type(type) {
}

AMateria::AMateria(AMateria const& src) : _type(src._type) {
}

AMateria & AMateria::operator=(AMateria const& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

std::string AMateria::getType() const {
	return _type;
}
