/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:02:42 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/11 12:54:31 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		bool _equipedStatus;
	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(AMateria const& src);
		AMateria & operator=(AMateria const& rhs);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
		virtual ~AMateria() {};
		std::string getType() const;
		void setEquiped();
		void setUnequiped();
		bool getEquipStatus() const;
};

