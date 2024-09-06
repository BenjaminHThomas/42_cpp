/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:19:35 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/06 12:42:55 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called.\n";
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "*cricket noises*";
	}
}

Brain::Brain(Brain &other) {
	std::cout << "Brain copy operator called.\n";
	if (other._ideas) {
		this->_ideas = new std::string[100];
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignment operator called.\n";
	if (other._ideas) {
		this->_ideas = new std::string[100];
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called.\n";
	if (this->_ideas) {
		delete [] this->_ideas;
	}
}

std::string* Brain::getIdeas() const {
	return this->_ideas;
}
