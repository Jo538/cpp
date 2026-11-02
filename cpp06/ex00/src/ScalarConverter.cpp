/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:52:05 by admin             #+#    #+#             */
/*   Updated: 2026/11/02 21:17:42 by admin            ###   ########.fr       */
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

// std::string "c", I know it's a char
// Convert the string to a char
// With static cast, convert char to other scalar types

void ScalarConverter::convert(const std::string& string)
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