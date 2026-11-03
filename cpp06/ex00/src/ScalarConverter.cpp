/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/03 19:39:37 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

// char --> c
// float --> 42.0f
// double --> 42.0
// int --> 42

// std::string "42", I know it's an int
// Convert the string to an int
// With static cast, convert int to other scalar types

void print(char v_char, int v_int, float v_float, double v_double)
{
	std::cout << "char: " << v_char << std::endl;
	std::cout << "int: " << v_int << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << v_float << 'f' << std::endl;
	std::cout << "double: " << v_double << std::endl;	
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
		case FLOAT:
		{
			str_to_float(item);	
			break;		
		}
		case DOUBLE:
		{
			str_to_double(item);	
			break;		
		}
		case UNKNOWN:
			return ;
	}
}