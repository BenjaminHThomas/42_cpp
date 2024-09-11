/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:42:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/11 11:39:15 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public virtual ICharacter
{
	private:
		std::string _name;
		const static int _maxInv = 4;
		AMateria** _inventory;
		int _nbEquiped;
		bool wpnEquiped(AMateria* m);
	public:
		Character(void);
		Character(std::string name);
		Character(const Character &other);
		Character & operator=(const Character &other);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
};

