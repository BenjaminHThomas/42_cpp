/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:30:35 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 16:01:07 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		/* data */
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		void makeSound() const;
		std::string getType() const;
};

