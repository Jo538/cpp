/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:10:26 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 12:01:53 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of command line arguments" << std::endl;
		return 1;
	}
	std::string item = argv[1];
	if (item.size() == 0)
	{
		std::cout << "Empty string" << std::endl;
		return 1;
	}
	ScalarConverter::convert(item);
	return 0;
}