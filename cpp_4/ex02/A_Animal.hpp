/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:19:38 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/06 13:27:17 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class A_Animal
{
	protected:
		std::string _type;
	public:
		A_Animal(void);
		A_Animal(std::string _type);
		A_Animal(const A_Animal& other);
		A_Animal& operator=(const A_Animal& other);
		virtual ~A_Animal();
		virtual void makeSound() const;
		std::string getType() const;
		virtual std::string getIdea(int idx) const = 0;
};
