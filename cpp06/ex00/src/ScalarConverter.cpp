/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/02 22:02:55 by admin            ###   ########.fr       */
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

static void register_type(const std::string& string, t_type *type)
{
	// for char --> length of string is 1 and char is alpha
	if (string.size() == 1 && std::isalpha(string[0]))
		*type = CHAR;
	// for int --> only has digits
	if (string.find_first_not_of("0123456789") == std::string::npos)
		*type = INT;
}

static void str_to_char(const std::string& string)
{
	char v_char = string[0];
	int v_int = static_cast<int>(v_char);
	float v_float = static_cast<float>(v_char);
	double v_double = static_cast<double>(v_char);	

	std::cout << "char: " << v_char << std::endl;
	std::cout << "int: " << v_int << std::endl;

	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(1) << v_float << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << v_double << std::endl;
}

static void str_to_int(const std::string& string)
{
	const char *str = string.c_str();
	char *end;

	int v_int = std::strtol(str, &end, 10);
	char v_char = static_cast<char>(v_int);
	float v_float = static_cast<float>(v_int);
	double v_double = static_cast<double>(v_int);

	std::cout << "char: " << v_char << std::endl;
	std::cout << "int: " << v_int << std::endl;

	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(1) << v_float << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << v_double << std::endl;
}

void ScalarConverter::convert(const std::string& string)
{
	t_type type;

	register_type(string, &type);
	if (type == CHAR)
		str_to_char(string);
	if (type == INT)
		str_to_int(string);
}