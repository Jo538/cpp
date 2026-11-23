/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:16:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 15:39:57 by jchartie         ###   ########.fr       */
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
	test.parseMap("data.csv", BitcoinExchange::FX);

	test.print();
	return 0;
}