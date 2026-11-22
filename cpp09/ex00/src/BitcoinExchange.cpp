/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:25:16 by admin             #+#    #+#             */
/*   Updated: 2026/11/22 17:21:37 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : fx(other.fx), price(other.price) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	fx = other.fx;
	price = other.price;
	
	return *this;
}

void BitcoinExchange::parsePrices(const std::string& priceFile)
{
	std::ifstream inFile(priceFile.c_str());
	
	if (!inFile)
		throw std::runtime_error("Error: Failed to open input file");
	
	// parse date and price into map
	// 1/ Put date into a string
	// 2/ Put price into a float
	
	std::string field1;
	float field2;
	
	std::getline(inFile, field1, ',');
	std::getline(inFile, field1) >> field2;

	price.insert(std::make_pair(field1, field2));
		
}

BitcoinExchange::ExchangeMap::const_iterator BitcoinExchange::getExchangePair() const
{
	ExchangeMap::const_iterator it = price.begin();
	
	return it;
}