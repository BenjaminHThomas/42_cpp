/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:54:11 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/14 18:54:25 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

class PmergeMe
{
private:
protected:
public:
	PmergeMe ();
	PmergeMe (const PmergeMe &other);
	~PmergeMe ();
	PmergeMe & operator=(const PmergeMe &other);
};

#endif /* PMERGEME_HPP */
