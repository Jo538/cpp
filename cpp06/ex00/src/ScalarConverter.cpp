/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/02 15:38:43 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>
#include "ScalarConverter.hpp"

// char --> c
// float --> 42.0f
// double --> 42.0
// int --> 42

static bool has_only_digits(const std::string& string)
{
	for (std::string::size_type i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
			return false;
	}
	return true;
}

static bool has_double_format(const std::string& string)
{
	for (std::string::size_type i = 0; i < string.size(); i++)
	{
		if (string.find_first_not_of("0123456789.") != std::string::npos)
			return false;
	}
	return true;	
}

void ScalarConverter::convert(const std::string& string)
{
	std::string type = "default";

	// if length of string is 1 and first char is alpha, type is char
	if (string.size() == 1 && std::isalpha(string[0]) == 1)
	{
		type = "char";	
	}
	// if all chars are digits, type is int
	else if (has_only_digits(string))
	{
		type = "int";
	}
	// all chars are digits except 1 .
	else if (has_double_format(string))
	{
		type = "double";		
	}
	std::cout << type << std::endl;	
}