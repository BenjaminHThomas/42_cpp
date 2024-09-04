/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:39:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/04 12:07:55 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		//
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap & operator=(const FragTrap &value);
		~FragTrap();
		void highFivesGuys(void);
};
