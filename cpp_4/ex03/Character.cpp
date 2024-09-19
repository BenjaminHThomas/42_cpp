/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:57:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 11:26:13 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() :
	_name("NoName"),
	_nbEquiped(0)
{
	_inventory = new AMateria*[_maxInv];
	for (int i = 0; i < _maxInv; ++i) {
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string name) :
	_name(name),
	_nbEquiped(0)
{
	_inventory = new AMateria*[_maxInv];
	for (int i = 0; i < _maxInv; ++i) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other) {
	_name = other._name;
	_inventory = new AMateria*[_maxInv];
	for (int i = 0; i < _maxInv; ++i) {
		if (i < other._nbEquiped && other._inventory[i] != NULL) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
	_nbEquiped = other._nbEquiped;
}

Character& Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other.getName();
		for (int i = 0; i < _maxInv; ++i) {
			if (_inventory[i] != NULL) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < _maxInv; ++i) {
			if (i < other._nbEquiped && other._inventory[i] != NULL) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
		_nbEquiped = other._nbEquiped;
	}
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

bool Character::wpnEquiped(AMateria *m) {
	if (!_nbEquiped) {
		return false;
	}
	for (int i = 0; i < _nbEquiped; ++i) {
		if (_inventory[i] == m) {
			return true;
		}
	}
	return false;
}

void Character::equip(AMateria *m) {
	if (_nbEquiped >= 4) {
		std::cout << _name << " can't equip more than 4 weapons!\n";
		return ;
	}
	if (!m) {
		std::cout << _name << " can't equip a null weapon!\n";
		return ;
	}
	if (m->getEquipStatus()) {
		std::cout << "This materia is already equiped.\n";
		return ;
	}
	std::cout << _name << " equips " << m->getType() << " in slot " << _nbEquiped << "\n";
	_inventory[_nbEquiped++] = m;
	m->setEquiped();
}

void Character::unequip(int idx) {
	if (_nbEquiped <= idx || idx < 0) {
		std::cout << _name << " can't unequip no weapon!\n";
		return ;
	}
	std::cout << _name << " unequips " << _inventory[idx]->getType() << " from slot " << idx << "\n";
	_inventory[idx]->setUnequiped();
	_inventory[idx] = NULL;
	--_nbEquiped;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= _nbEquiped || idx < 0 || _inventory[idx] == NULL) {
		std::cout << _name << " can't attack with no weapon!\n";
		return ;
	}
	_inventory[idx]->use(target);
}

Character::~Character() {
	for (int i = 0; i < _maxInv; ++i) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	delete [] _inventory;
}