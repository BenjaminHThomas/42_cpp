/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:06:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/14 11:07:28 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>

class RPN
{
private:
protected:
public:
	RPN ();
	RPN (const RPN & other);
	~RPN ();
	RPN & operator=(const RPN & other);
};

#endif /* RPN_HPP */
