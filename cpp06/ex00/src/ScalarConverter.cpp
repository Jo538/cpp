/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/06 13:47:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& item)
{	
	switch (register_type(item))
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