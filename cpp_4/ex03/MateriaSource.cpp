/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:50:23 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 11:26:29 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _numLearned(0) {
	_memory = new AMateria*[_memorySize];
	for (int i = 0; i < _memorySize; ++i) {
		_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	if (this != &other) {
		_memory = new AMateria*[_memorySize];
		for (int i = 0; i < _memorySize; ++i) {
			if (other._memory[i]) {
				_memory[i] = other._memory[i]->clone();
			} else {
				_memory[i] = NULL;
			}
		}
		_numLearned = other._numLearned;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _memorySize; ++i) {
			if (_memory[i] != NULL) {
				delete _memory[i];
				_memory[i] = NULL;
			}
		}
		_numLearned = other._numLearned;
		for (int i = 0; i < other._numLearned; ++i) {
			_memory[i] = other._memory[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (_numLearned >= 4) {
		std::cout << "Too many spells to learn another.\n";
		return ;
	}
	if (!m) {
		std::cout << "Can't learn a null spell.\n";
		return ;
	}
	_memory[_numLearned++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	std::string newType = type;

	for (std::string::size_type i = 0; i < type.size(); ++i) {
		if (type[i] >= 'A' && type[i] <= 'Z')
			newType[i] = type[i] + 32;
		else
			newType[i] = type[i];
	}
	for (int i = 0; i < _numLearned; ++i) {
		if (_memory[i] && _memory[i]->getType() == newType) {
			return _memory[i]->clone();
		}
	}
	return 0;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < _memorySize; ++i) {
		if (_memory[i] != NULL)
			delete _memory[i];
	}
	delete [] _memory;
}