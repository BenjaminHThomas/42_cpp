/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/11 17:35:18 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<const tm, double> _btcPrices;

	private:
		std::tm getDate(const std::string & line);
		double getPrice(const std::string & line);

	public:
		class invalidInput;

	public:
		void readCsv(const std::string & fname);
		void debugPrint(void) const;

	public:
		BitcoinExchange ();
		BitcoinExchange (const std::string & fname);
		BitcoinExchange (const BitcoinExchange &other);
		~BitcoinExchange ();
		BitcoinExchange & operator=(const BitcoinExchange &other);
};

#endif
