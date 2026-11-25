/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:48:00 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 18:31:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}

	std::string operation = argv[1];
	
	RPN ops;
	
	try
	{
		ops.calculate(operation);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}