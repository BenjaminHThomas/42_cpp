/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:24:55 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 16:01:13 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		//
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		void makeSound() const;
		std::string getType() const;
};

