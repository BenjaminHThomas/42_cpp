/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/10 12:40:38 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange
{
private:
protected:
public:
	BitcoinExchange ();
	BitcoinExchange (const BitcoinExchange &bitcoinexchange);
	~BitcoinExchange ();
	BitcoinExchange & operator=(const BitcoinExchange &bitcoinexchange);
};

#endif /* BITCOINEXCHANGE_HPP */
