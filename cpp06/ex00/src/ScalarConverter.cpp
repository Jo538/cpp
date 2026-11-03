/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/03 15:58:08 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <limits>
#include "ScalarConverter.hpp"

// char --> c
// float --> 42.0f
// double --> 42.0
// int --> 42

// std::string "42", I know it's an int
// Convert the string to an int
// With static cast, convert int to other scalar types

static void print(char v_char, int v_int, float v_float, double v_double)
{
	std::cout << "char: " << v_char << std::endl;
	std::cout << "int: " << v_int << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << v_float << 'f' << std::endl;
	std::cout << "double: " << v_double << std::endl;	
}

static Type register_type(const std::string& item)
{
	// for char --> length of string is 1 and char is alpha
	if (item.size() == 1 && std::isalpha(item[0]))
		return CHAR;
	// for int --> only has digits
	if (item.find_first_not_of("0123456789") == std::string::npos)
		return INT;
	return UNKNOWN;
}

static void str_to_char(const std::string& item)
{
	char v_char = item[0];
	int v_int = static_cast<int>(v_char);
	float v_float = static_cast<float>(v_char);
	double v_double = static_cast<double>(v_char);	
	
	print(v_char, v_int, v_float, v_double);
}

static void str_to_int(const std::string& item)
{
	const char *str = item.c_str();
	char *end;

	long tmp = std::strtol(str, &end, 10);
	if (errno == ERANGE)
	{
		std::cerr << "Error: long out of range" << std::endl;
		return ;
	}
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: int out of range" << std::endl;
		return ;		
	}
	
	int v_int = static_cast<int>(tmp);
	char v_char = static_cast<char>(v_int);
	float v_float = static_cast<float>(v_int);
	double v_double = static_cast<double>(v_int);

	print(v_char, v_int, v_float, v_double);
}

void ScalarConverter::convert(const std::string& item)
{
	Type type = register_type(item);
	
	switch (type)
	{
		case CHAR:
		{
			str_to_char(item);
			break;	
		}
		case INT:
		{
			str_to_int(item);	
			break;		
		}
		case UNKNOWN:
			return ;
	}
}