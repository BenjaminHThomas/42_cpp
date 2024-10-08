/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:18:08 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 11:27:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _equipedStatus(false) {
}

AMateria::AMateria(std::string const& type) : _type(type), _equipedStatus(false) {
}

AMateria::AMateria(AMateria const& src) : _type(src._type), _equipedStatus(false) {
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

void AMateria::setEquiped() {
	_equipedStatus = true;
}

void AMateria::setUnequiped() {
	_equipedStatus = false;
}

bool AMateria::getEquipStatus() const {
	return _equipedStatus;
}
