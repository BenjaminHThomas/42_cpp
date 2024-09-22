/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:28:30 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/22 15:52:57 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer() {};
	Serializer(const Serializer &Serializer) {(void)Serializer;};
	Serializer & operator=(const Serializer &Serializer) {(void)Serializer; return *this;};
	
public:
	virtual ~Serializer();
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif /* SERIALIZER_HPP */
