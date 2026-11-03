/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:34:47 by admin             #+#    #+#             */
/*   Updated: 2026/11/03 19:38:43 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include "ScalarConverter.hpp"

void str_to_char(const std::string& item)
{
	char v_char = item[0];
	int v_int = static_cast<int>(v_char);
	float v_float = static_cast<float>(v_char);
	double v_double = static_cast<double>(v_char);	
	
	print(v_char, v_int, v_float, v_double);
}

void str_to_int(const std::string& item)
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

void str_to_float(const std::string& item)
{
	const char *str = item.c_str();
	char *end;
	
	double tmp = std::strtod(str, &end);
	if (errno == ERANGE)
	{
		std::cerr << "Error: double out of range" << std::endl;
		return ;
	}
	if (tmp < -std::numeric_limits<float>::max() || tmp > std::numeric_limits<float>::max())
	{
		std::cerr << "Error: float out of range" << std::endl;
		return ;		
	}

	float v_float = static_cast<float>(tmp);
	char v_char = static_cast<char>(v_float);
	int v_int = static_cast<int>(v_float);
	double v_double = static_cast<double>(v_float);

	print(v_char, v_int, v_float, v_double);
}

void str_to_double(const std::string& item)
{
	const char *str = item.c_str();
	char *end;
	
	double v_double = std::strtod(str, &end);
	if (errno == ERANGE)
	{
		std::cerr << "Error: double out of range" << std::endl;
		return ;
	}

	float v_float = static_cast<float>(v_double);
	char v_char = static_cast<char>(v_float);
	int v_int = static_cast<int>(v_float);

	print(v_char, v_int, v_float, v_double);
}
