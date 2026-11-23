/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:16:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 12:46:51 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Missing input file" << std::endl;
		return 1;
	}
	
	std::string priceFile = argv[1];
	BitcoinExchange test;
	
	test.parseMap(priceFile, BitcoinExchange::PRICE);
	BitcoinExchange::ExchangeMap::const_iterator it = test.getPair(BitcoinExchange::PRICE);
	std::cout << "first: " << it->first
	          << "\nsecond: " << it->second << std::endl; 

	test.parseMap("data.csv", BitcoinExchange::FX);
	BitcoinExchange::ExchangeMap::const_iterator it2 = test.getPair(BitcoinExchange::FX);
	std::cout << "first: " << it2->first
	          << "\nsecond: " << it2->second << std::endl; 

	test.print(it, it2);
	return 0;
}