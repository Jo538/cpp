/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:25:16 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 12:00:55 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void BitcoinExchange::parsePrices(const std::string& priceFile)
{
	std::ifstream inFile(priceFile.c_str());
	
	if (!inFile)
		throw std::runtime_error("Error: Failed to open input file");
	
	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::string date;
	float price;

	std::getline(inFile, date, ',');
	inFile >> price;
	
	_price.insert(std::make_pair(date, price));
		
}

BitcoinExchange::ExchangeMap::const_iterator BitcoinExchange::getExchangePair() const
{
	ExchangeMap::const_iterator it = _price.begin();
	
	return it;
}