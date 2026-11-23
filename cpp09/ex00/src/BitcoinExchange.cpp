/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:25:16 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 16:24:10 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

void BitcoinExchange::parsePair(std::ifstream& inFile, Map type)
{
	std::string date;
	float value;

	std::getline(inFile, date, ',');
	inFile >> value;
	inFile.ignore();
	
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
	
	while (inFile)
		parsePair(inFile, type);	
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
		itFX = _fx.upper_bound(itPrice->first);
		--itFX;
		format(itPrice, itFX);
	}
}