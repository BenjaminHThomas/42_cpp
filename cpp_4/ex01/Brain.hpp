/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:16:20 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/19 19:14:05 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Brain
{
	protected:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
};

