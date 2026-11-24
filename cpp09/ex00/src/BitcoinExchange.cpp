/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:25:16 by admin             #+#    #+#             */
/*   Updated: 2026/11/24 19:31:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <limits>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _fx(other._fx), _price(other._price) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	_fx = other._fx;
	_price = other._price;
	
	return *this;
}

void BitcoinExchange::parsePair(std::string& line, Map type)
{
	std::istringstream fields(line);
	
	std::string date;
	std::getline(fields, date, ',');

	float value;
	fields >> value;
	
	switch(type)
	{
		case PRICE:
			_price.insert(std::make_pair(date, value));
			break;
		case FX:
			_fx.insert(std::make_pair(date, value));
			break;
	}
}

void BitcoinExchange::parseMap(const std::string& file, Map type)
{
	std::ifstream inFile(file.c_str());
	
	if (!inFile)
		throw std::runtime_error("Error: Failed to open input file");
	
	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::string line;
	
	while (std::getline(inFile, line))
		parsePair(line, type);	
}

float BitcoinExchange::product(const_it& itPrice, const_it& itFX) const
{
	return (itPrice->second * itFX->second);
}

void BitcoinExchange::format(const_it& itPrice, const_it& itFX)
{
	const int padding = 12;
	
	std::cout << std::setw(padding) << std::left << itPrice->first << "| "
	          << itPrice->second << " * " << itFX->second
	          << " ==> " << product(itPrice, itFX);
		
	if (itPrice->first != itFX->first)	
		 std::cout << " [FX closest date match: " << itFX->first << "]";
	std::cout << std::endl;		
}

void BitcoinExchange::print()
{
	const_it itPrice = _price.begin();
	const_it itePrice = _price.end();

	const_it itFX;
	
	for (; itPrice != itePrice; ++itPrice)
	{
		if (!isGoodInput(itPrice))
			continue;
		itFX = _fx.upper_bound(itPrice->first);
		if (itFX == _fx.begin())
		{
			const int padding = 12;
			std::cerr << std::setw(padding) << std::left << itPrice->first << "| " << "Error: No FX satisfies this date\n";
			return ;
		}
		--itFX;
		format(itPrice, itFX);
	}
}

bool BitcoinExchange::hasRightDateFormat(const_it& itPrice)
{
	std::istringstream iss(itPrice->first);
	int month;
	int day;

	iss.ignore(std::numeric_limits<std::streamsize>::max(), '-');
	iss >> month;

	const int padding = 12;
	
	if (month < 1 || month > 12)
	{
		std::cerr << std::setw(padding) << std::left << itPrice->first << "| " << "Error: Bad Input" << std::endl;
		return false;
	}

	iss.ignore(std::numeric_limits<std::streamsize>::max(), '-');
	iss >> day;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(itPrice))
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
	{
		std::cerr << std::setw(padding) << std::left << itPrice->first << "| " << "Error: Bad input\n";
		return false;
	}
	return true;
}

bool BitcoinExchange::isGoodInput(const_it& itPrice)
{
	const int padding = 12;
	
	if (!hasRightDateFormat(itPrice))
		return false;
	
	if (itPrice->second < 0 || itPrice->second > 1000)
	{
		std::cerr << std::setw(padding) << std::left << itPrice->first << "| " << "Error: Price not within [0, 1000] range\n";
		return false;
	}
	
	return true;
}

bool BitcoinExchange::isLeapYear(const_it& itPrice)
{
	std::istringstream iss(itPrice->first);

	int year;
	iss >> year;

	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 != 0)
		return false;
	return true;
}