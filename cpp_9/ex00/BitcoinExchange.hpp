/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/10 12:56:05 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

struct Date {
	int year;
	int month;
	int day;
};

class BitcoinExchange
{
	private:
		std::map<Date, double> _btcPrices;

	public:
		BitcoinExchange ();
		BitcoinExchange (const BitcoinExchange &other);
		~BitcoinExchange ();
		BitcoinExchange & operator=(const BitcoinExchange &other);
};

#endif /* BITCOINEXCHANGE_HPP */
