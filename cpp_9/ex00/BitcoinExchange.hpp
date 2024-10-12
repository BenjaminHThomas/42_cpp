/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:32 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/12 14:09:25 by bthomas          ###   ########.fr       */
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
#include <cstring>

#define TIMET_DAY (24 * 60 * 60)
class BitcoinExchange
{
	private:
		std::map<time_t, double> _btcPrices;

	private:
		std::tm getDate(const std::string & line, char delim);
		double getPrice(const std::string & line, char delim);
		std::string dateToString(const time_t time) const;
		time_t getClosestDate(time_t & date);

	public:
		class invalidInput;

	public:
		std::map<time_t, double> readCsv(const std::string & fname, char delim);
		void printResults(const std::string & fname);
		void convertResults(void);

	public:
		BitcoinExchange ();
		BitcoinExchange (const BitcoinExchange &other);
		~BitcoinExchange ();
		BitcoinExchange & operator=(const BitcoinExchange &other);
};

#endif
