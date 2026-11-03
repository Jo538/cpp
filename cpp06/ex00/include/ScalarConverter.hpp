/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:42:58 by admin             #+#    #+#             */
/*   Updated: 2026/11/03 15:03:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string> 

enum Type
{
	CHAR,
	INT
};

class ScalarConverter
{
public:
	static void convert(const std::string& argument);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	const ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
};

#endif