/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:00:35 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 17:10:49 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};

