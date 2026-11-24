/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:16:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/24 20:25:05 by admin            ###   ########.fr       */
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
	
	if (test.parseMap(priceFile, BitcoinExchange::PRICE))
		return 1;
	if (test.parseMap("data.csv", BitcoinExchange::FX))
		return 1;

	test.print();
	
	return 0;
}