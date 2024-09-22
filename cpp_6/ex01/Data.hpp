/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:45:15 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/22 16:00:44 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
private:
	int _x;
	int _y;
public:
	Data(int x = 42, int y = 420);
	Data(const Data &Data);
	~Data();
	Data & operator=(const Data &Data);
	int getX() const;
	int getY() const;
};

std::ostream& operator<<(std::ostream& o, const Data &d);
#endif /* DATA_HPP */

