/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/03 15:30:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
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

	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(1) << v_float << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << v_double << std::endl;	
}

static Type register_type(const std::string& string)
{
	// for char --> length of string is 1 and char is alpha
	if (string.size() == 1 && std::isalpha(string[0]))
		return CHAR;
	// for int --> only has digits
	if (string.find_first_not_of("0123456789") == std::string::npos)
		return INT;
	return UNKNOWN;
}

static void str_to_char(const std::string& string)
{
	char v_char = string[0];
	int v_int = static_cast<int>(v_char);
	float v_float = static_cast<float>(v_char);
	double v_double = static_cast<double>(v_char);	
	
	print(v_char, v_int, v_float, v_double);
}

static void str_to_int(const std::string& string)
{
	const char *str = string.c_str();
	char *end;

	int v_int = std::strtol(str, &end, 10); //TODO: check that string was not too big to store long + long must be able to hold in int, check range
	char v_char = static_cast<char>(v_int);
	float v_float = static_cast<float>(v_int);
	double v_double = static_cast<double>(v_int);

	print(v_char, v_int, v_float, v_double);
}

void ScalarConverter::convert(const std::string& string)
{
	Type type;
	void (*func[])(const std::string& string) = {str_to_char, str_to_int};
	
	type = register_type(string);
	
	switch (type)
	{
		case CHAR:
			return func[0](string);
		case INT:
			return func[1](string);
		case UNKNOWN:
			return ;
	}
}