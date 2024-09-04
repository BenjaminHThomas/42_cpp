/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:19:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 17:14:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string _type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void makeSound() const;
		virtual std::string getType() const;
};
