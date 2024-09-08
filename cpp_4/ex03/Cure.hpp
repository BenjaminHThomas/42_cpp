/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:06:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/08 16:45:49 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		//
	public:
		Cure(void);
		Cure(Cure const& src);
		Cure & operator=(Cure const& rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
		~Cure();
};

