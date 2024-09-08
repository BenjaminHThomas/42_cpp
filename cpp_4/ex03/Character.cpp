/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:57:14 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/08 16:47:51 by bthomas          ###   ########.fr       */
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

void Character::equip(AMateria *m) {
	if (_nbEquiped >= 4) {
		std::cout << _name << " can't equip more than 4 weapons!\n";
		return ;
	}
	std::cout << _name << " equips " << m->getType() << " in slot " << _nbEquiped << "\n";
	_inventory[_nbEquiped++] = m;
}

void Character::unequip(int idx) {
	if (_nbEquiped <= idx || idx < 0) {
		std::cout << _name << " can't unequip no weapon!\n";
		return ;
	}
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
		}
	}
	delete [] _inventory;
}