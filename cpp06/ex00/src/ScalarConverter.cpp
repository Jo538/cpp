/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 11:59:08 by admin            ###   ########.fr       */
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

void ScalarConverter::convert(const std::string& item)
{
	Type type = register_type(item);
	
	switch (type)
	{
		case SPECIAL:
		{
			str_to_special(item);
			break;				
		}
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
		{
			std::cout << item << ": unknown scalar type" << std::endl;
		};
	}
}