/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:26:44 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/29 20:24:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <class T>
class Easyfind {
private:
protected:
public:
	Easyfind();
	Easyfind(const Easyfind &easyfind);
	~Easyfind();
	Easyfind & operator=(const Easyfind &easyfind);
};
#endif /* EASYFIND_HPP */


