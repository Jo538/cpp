/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:42:58 by admin             #+#    #+#             */
/*   Updated: 2026/11/02 21:52:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string> 

typedef enum e_type
{
	CHAR,
	INT
}	t_type;

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