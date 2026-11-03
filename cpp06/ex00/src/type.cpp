/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:33:10 by admin             #+#    #+#             */
/*   Updated: 2026/11/03 20:21:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <algorithm>
#include <cctype>
#include "ScalarConverter.hpp"

static bool isDouble(const std::string& item)
{
	std::string allowed = "0123456789.";
	size_t i = 0;
	int dot_count = 0;
	int digit_count = 0;

	if (item[0] == '+' || item[0] == '-')
		i++;
	for (; i < item.size(); i++)
	{
		if (allowed.find(item[i]) == std::string::npos)
			return false;
		if (item[i] == '.')
			dot_count++;
		if (std::isdigit(item[i]))
			digit_count++;		
	}
	if (dot_count != 1 || digit_count == 0) 
		return false;
	return true;	
}

static bool isFloat(const std::string& item)
{
	std::string allowed = "0123456789.f";
	size_t i = 0;
	int dot_count = 0;
	int f_count = 0;
	int digit_count = 0;

	if (item[0] == '+' || item[0] == '-')
		i++;
	for (; i < item.size(); i++)
	{
		if (allowed.find(item[i]) == std::string::npos)
			return false;
		if (item[i] == '.')
			dot_count++;
		if (item[i] == 'f')
			f_count++;	
		if (std::isdigit(item[i]))
			digit_count++;		
	}
	if (dot_count != 1 || f_count != 1 || digit_count == 0) 
		return false;
	if (item[item.size() - 1] != 'f')
		return false;
	return true;
}

Type register_type(const std::string& item)
{
	if (item.size() == 1 && std::isalpha(item[0]))
		return CHAR;
	if (item.find_first_not_of("0123456789") == std::string::npos)
		return INT;
	if (isFloat(item))
		return FLOAT;
	if (isDouble(item))
		return DOUBLE;
	return UNKNOWN;
}
