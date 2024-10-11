/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/11 17:38:13 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange::invalidInput : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: Invalid csv input.\n";
		}
};

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const std::string & fname)
{
	readCsv(fname);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_btcPrices = other._btcPrices;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_btcPrices = other._btcPrices;
	}
	return *this;
}

static std::tm getInvalidDate() {
	std::tm invalidDate = {};
	invalidDate.tm_year = -1;
	invalidDate.tm_mon = -1;
	invalidDate.tm_mday = -1;
	return invalidDate;
}

static int charCount(const std::string & s, char c) {
	int count = 0;
	std::string::const_iterator it;
	for (it = s.begin(); it != s.end(); ++it) {
		if (*it == c) {
			++count;
		}
	}
	return count;
}


std::tm BitcoinExchange::getDate(const std::string & line) {
	if (charCount(line, '-') != 2 || charCount(line, ',') != 1) {
		return getInvalidDate();
	}
	std::string::size_type commaPos = line.find(",");
	std::string dateString = line.substr(0, commaPos);
	if (dateString.size() != 10) {
		return getInvalidDate();
	}
	size_t dash1Pos = dateString.find_first_of('-');
	size_t dash2Pos = dateString.find(dash1Pos, '-');
	std::string yearString = dateString.substr(0, dash1Pos);
	std::string monthString = dateString.substr(dash1Pos, 2);
	std::string dayString = dateString.substr(dash2Pos, 2);
	int year, month, day;
	year = atoi(yearString.c_str());
	month = atoi(monthString.c_str());
	day = atoi(dayString.c_str());
	if (year < 0 || month > 12 || month < 1 || day > 31 || day < 1) {
		return getInvalidDate();
	}
	std::tm _time;
	_time.tm_year = year;
	_time.tm_mon = month;
	_time.tm_mday = day;
	return _time;
}

double BitcoinExchange::getPrice(const std::string & line) {
	if (charCount(line, '-') != 2 || charCount(line, ',') != 1) {
		return -1;
	}
	std::string::size_type commaPos = line.find(",");
	std::string priceString = line.substr(commaPos);
	std::istringstream iss(priceString);
	double price;
	iss >> price;
	if (iss.fail()) {
		return -1;
	}
	return price;
}

void BitcoinExchange::readCsv(const std::string & fname) {
	std::ifstream inFile;
	inFile.open(fname.c_str());
	if (!inFile.is_open()) {
		throw std::runtime_error("Could not open file");
	}
	int i = 0;
	std::string line;
	std::getline(inFile, line); // skip column names
	while (std::getline(inFile, line)) {
		const tm date = getDate(line);
		double price = getPrice(line);
		_btcPrices.insert(std::map<tm, double>::value_type(date, price));
	}
	inFile.close();
}

void BitcoinExchange::debugPrint(void) const {
	std::map<std::tm, double>::const_iterator it;
	for (it = _btcPrices.begin(); it != _btcPrices.end(); ++it) {
		std::tm curr = it->first;
		std::cout << curr.tm_mday << "/" << curr.tm_mon << "/" << curr.tm_year
		<< "\t$" << it->second << std::endl;
	}
}