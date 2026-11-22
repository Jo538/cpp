/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:16:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/22 17:28:27 by admin            ###   ########.fr       */
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
	
	test.parsePrices(priceFile);
	BitcoinExchange::ExchangeMap::const_iterator it = test.getExchangePair();
	std::cout << "first: " << it->first
	          << "\nsecond: " << it->second << std::endl; 
	
	return 0;
}