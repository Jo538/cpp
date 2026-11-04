/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:42:58 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 11:04:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string> 

enum Type
{
	UNKNOWN,
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
public:
	static void convert(const std::string& item);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	const ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
};

Type register_type(const std::string& item);
void str_to_char(const std::string& item);
void str_to_int(const std::string& item);
void str_to_float(const std::string& item);
void str_to_double(const std::string& item);
void str_to_special(const std::string& item);

void print(char v_char, int v_int, float v_float, double v_double);

#endif