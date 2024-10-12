/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:40:40 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/12 14:34:00 by bthomas          ###   ########.fr       */
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
	_btcPrices = readCsv("data.csv", ',');
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_btcPrices = other._btcPrices;
	if (_btcPrices.empty()) {
		throw invalidInput();
	}
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

static std::string stripSpace(const std::string & s) {
	std::string replacement;
	for (std::string::size_type i = 0; i < s.size(); ++i) {
		if (!std::isspace(s[i])) {
			replacement += s[i];
		}
	}
	return replacement;
}

std::tm BitcoinExchange::getDate(const std::string & line, char delim) {
	if (charCount(line, '-') != 2 || charCount(line, delim) != 1) {
		return getInvalidDate();
	}
	std::string::size_type delimPos = line.find(delim);
	std::string dateString = line.substr(0, delimPos);
	if (dateString.size() != 10) {
		return getInvalidDate();
	}
	
	int year, month, day;
	char delimiter1, delimiter2;
	std::istringstream iss(dateString);
	if (!(iss >> year >> delimiter1 >> month >> delimiter2 >> day) ||
		delimiter1 != '-' || delimiter2 != '-') {
		return getInvalidDate();
	}

	struct tm timeinfo;
	memset(&timeinfo, 0, sizeof(struct tm));
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	char buffer[11];
	if (strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeinfo) == 0) {
		return getInvalidDate();
	}
	return timeinfo;
}

double BitcoinExchange::getPrice(const std::string & line, char delim) {
	if (charCount(line, delim) != 1) {
		return -1;
	}
	std::string::size_type delimPos = line.find(delim);
	std::string priceString = line.substr(delimPos + 1);
	std::istringstream iss(priceString);
	double price;
	iss >> price;
	if (iss.fail() || price < 0) {
		return -1;
	}
	return price;
}

std::map<time_t, double> BitcoinExchange::readCsv(const std::string & fname, char delim) {
	std::ifstream inFile;
	inFile.open(fname.c_str());
	if (!inFile.is_open()) {
		throw invalidInput();
	}
	std::string line;
	std::getline(inFile, line); // skip column names
	std::map<time_t, double> data;
	while (std::getline(inFile, line)) {
		line = stripSpace(line);
		if (line.empty())
			continue ;
		tm dateStruct = getDate(line, delim);
		double price = getPrice(line, delim);
		time_t date = mktime(&dateStruct);
		if (data.find(date) != data.end())
			continue ; // skip duplicates
		std::pair<time_t, double> entry(date, price);
		data.insert(entry);
	}
	inFile.close();
	return data;
}

std::string BitcoinExchange::dateToString(const time_t time) const {
	struct tm *tmTime = localtime(&time);
	if (tmTime->tm_year == 1898) {
		return "Invalid Date.\n";
	}
	char buffer[11];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", tmTime);
	return buffer;
}

time_t BitcoinExchange::getClosestDate(time_t & date) {
	if (_btcPrices.find(date) != _btcPrices.end()) {
		return date;
	}
	time_t firstDate = _btcPrices.begin()->first;
	if (date < firstDate) {
		tm invalidTm = getInvalidDate();
		time_t invalidTime = mktime(&invalidTm);
		return invalidTime;
	}
	while (date >= firstDate) {
		date -= TIMET_DAY;
		if (_btcPrices.find(date) != _btcPrices.end())
			return date;
	}
	tm invalidTm = getInvalidDate();
	time_t invalidTime = mktime(&invalidTm);
	return invalidTime;
}

void BitcoinExchange::printResults(const std::string & fname) {
	std::ifstream inFile;
	inFile.open(fname.c_str());
	if (!inFile.is_open()) {
		throw std::runtime_error("Could not open file");
	}
	std::string line;
	std::getline(inFile, line); // skip column names
	while (std::getline(inFile, line)) {
		line = stripSpace(line);
		std::string::size_type delimPos = line.find('|');
		std::string dateString = line.substr(0, delimPos);
		if (delimPos == std::string::npos) {
			std::cerr << "Error: bad input => " << dateString << "\n";
			continue ;
		}
		std::string amtString = line.substr(delimPos + 1);
		double amt = getPrice(line, '|');
		if (amt < 0) {
			std::cerr << "Error: invalid amount => " << amtString << "\n";
			continue ;
		}
		tm tmTime = getDate(line, '|');
		time_t date = mktime(&tmTime);
		if ((date + TIMET_DAY * 100) > _btcPrices.rbegin()->first) {
			std::cerr << "Error: date is too far into the future => " << dateString << "\n";
			continue ;
		}
		date = getClosestDate(date);
		if (_btcPrices.find(date) == _btcPrices.end()) {
			std::cerr << "Error: date not found in csv => " << dateString << "\n";
			continue ;
		}
		std::string formattedDateString = dateToString(date);
		if (formattedDateString == "1898-11-29") {
			std::cerr << "Error: bad input => " << dateString << "\n";
			continue ;
		}
		std::cout << dateString << " => " << amtString << " = " << (amt * _btcPrices.at(date)) << "\n";
	}
	inFile.close();
}