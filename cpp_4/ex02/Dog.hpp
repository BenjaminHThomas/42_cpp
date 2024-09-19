/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:30:35 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:23:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual A_Animal
{
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		void makeSound() const;
		std::string getIdea(int idx) const;
};

