/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:25:16 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 12:51:05 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

void BitcoinExchange::parseMap(const std::string& file, Map type)
{
	std::ifstream inFile(file.c_str());
	
	if (!inFile)
		throw std::runtime_error("Error: Failed to open input file");
	
	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::string date;
	float value;

	std::getline(inFile, date, ',');
	inFile >> value;
	
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

BitcoinExchange::const_it BitcoinExchange::getPair(Map type) const
{
	const_it it;
	
	switch(type)
	{
		case PRICE:
			it = _price.begin();
			break;
		case FX:
			it = _fx.begin();
			break;
	}
	return it;
}

float BitcoinExchange::product(const_it& itPrice, const_it& itFX) const
{
	return (itPrice->second * itFX->second);
}

void BitcoinExchange::print(const_it& itPrice, const_it& itFX)
{
	std::cout << "date | value\n";
	std::cout << itPrice->first << ", " << itFX->second << " ==> " << product(itPrice, itFX) << std::endl;
}