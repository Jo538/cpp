/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:16:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/20 18:20:46 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: Missing input file" << std::endl;
		return 1;
	}
	BitcoinExchange test;
	return 0;
}