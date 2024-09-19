/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:19:35 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:29:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called.\n";
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "*cricket noises*";
	}
}

Brain::Brain(Brain &other) {
	std::cout << "Brain copy operator called.\n";
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignment operator called.\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called.\n";
}
