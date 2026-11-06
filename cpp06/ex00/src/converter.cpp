/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:34:47 by admin             #+#    #+#             */
/*   Updated: 2026/11/06 13:47:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "ScalarConverter.hpp"

static const int FLOAT_DIGITS = 7;
static const int DOUBLE_DIGITS = 15;

static void print_floating(const std::string& label, double value,
	const char *suffix, int precision)
{
	std::ostringstream out;

	if (value == std::floor(value))
		out << std::fixed << std::setprecision(1) << value;
	else
	{
		out << std::setprecision(precision) << value;
		if (out.str().find_first_of(".e") == std::string::npos)
			out << ".0";
	}
	std::cout << label << ": " << out.str() << suffix << std::endl;
}

void str_to_char(const std::string& item)
{
	char v_char;
	if (item.size() == 3)
		v_char = item[1];
	else
		v_char = item[0];
	int v_int = static_cast<int>(v_char);
	float v_float = static_cast<float>(v_char);
	double v_double = static_cast<double>(v_char);	
	
	std::cout << "char: '" << v_char << "'" << std::endl;
	std::cout << "int: " << v_int << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << v_float << 'f' << std::endl;
	std::cout << "double: " << v_double << std::endl;	
}

void str_to_int(const std::string& item)
{
	const char *str = item.c_str();
	char *end;

	errno = 0;
	long tmp = std::strtol(str, &end, 10);
	if (errno == ERANGE
		|| tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
	{
		str_to_double(item);
		return ;
	}
	
	int v_int = static_cast<int>(tmp);
	float v_float = static_cast<float>(v_int);
	double v_double = static_cast<double>(v_int);

	if (v_int < 0 || v_int > 255)
	{
		std::cout << "char: equivalent doesn't exist" << std::endl;
	}
	else if (!std::isprint(v_int))
	{
		std::cout << "char: not printable" << std::endl;
	}
	else
	{
		char v_char = static_cast<char>(v_int);
		std::cout << "char: '" << v_char << "'" << std::endl;
	}
	
	std::cout << "int: " << v_int << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << v_float << 'f' << std::endl;
	std::cout << "double: " << v_double << std::endl;	
}

void str_to_float(const std::string& item)
{
	const char *str = item.c_str();
	char *end;
	
	errno = 0;
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
	double v_double = static_cast<double>(v_float);

	if (v_float < 0 || v_float > 255)
	{
		std::cout << "char: equivalent doesn't exist" << std::endl;
	}
	else if (!std::isprint(v_float))
	{
		std::cout << "char: not printable" << std::endl;
	}
	else
	{
		char v_char = static_cast<char>(v_float);
		std::cout << "char: '" << v_char << "'" << std::endl;
	}
	if (v_double < std::numeric_limits<int>::min() || v_double > std::numeric_limits<int>::max())
	{
		std::cout << "int: out of range" << std::endl;
	}
	else
	{
		int v_int = static_cast<int>(v_float);		
		std::cout << "int: " << v_int << std::endl;
	}

	print_floating("float", v_float, "f", FLOAT_DIGITS);
	print_floating("double", v_double, "", FLOAT_DIGITS);
}

void str_to_double(const std::string& item)
{
	const char *str = item.c_str();
	char *end;

	errno = 0;
	double v_double = std::strtod(str, &end);
	if (errno == ERANGE)
	{
		std::cerr << "Error: double out of range" << std::endl;
		return ;
	}

	if (v_double < 0 || v_double > 255)
	{
		std::cout << "char: equivalent doesn't exist" << std::endl;
	}
	else if (!std::isprint(v_double))
	{
		std::cout << "char: not printable" << std::endl;
	}
	else
	{
		char v_char = static_cast<char>(v_double);
		std::cout << "char: '" << v_char << "'" << std::endl;
	}

	if (v_double < std::numeric_limits<int>::min() || v_double > std::numeric_limits<int>::max())
	{
		std::cout << "int: out of range" << std::endl;
	}
	else
	{
		int v_int = static_cast<int>(v_double);		
		std::cout << "int: " << v_int << std::endl;
	}

	if (v_double < -std::numeric_limits<float>::max() || v_double > std::numeric_limits<float>::max())
	{
		std::cout << "float: out of range" << std::endl;
	}
	else
	{
		float v_float = static_cast<float>(v_double);
		print_floating("float", v_float, "f", FLOAT_DIGITS);
	}

	print_floating("double", v_double, "", DOUBLE_DIGITS);
}

void str_to_special(const std::string& item)
{
	if (item == "nan" || item == "nanf")
	{
		std::cout << "char: equivalent doesn't exist" << std::endl; 
		std::cout << "int: equivalent doesn't exist" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (item == "+inf" || item == "+inff")
	{
		std::cout << "char: equivalent doesn't exist" << std::endl;
		std::cout << "int: equivalent doesn't exist" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (item == "-inf" || item == "-inff")
	{
		std::cout << "char: equivalent doesn't exist" << std::endl;
		std::cout << "int: equivalent doesn't exist" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}	
}
