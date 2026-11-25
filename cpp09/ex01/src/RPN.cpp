/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:21:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 17:55:53 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

// 1000000000000000 --> 1 number and 1 operator or more

void RPN::evaluate(const char c, int pos)
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Error");
	
	if (pos % 2 == 1)
		throw std::runtime_error("Error");

	double right = _numbers.top();
	_numbers.pop();
	double left = _numbers.top();
	_numbers.pop();

	switch(c)
	{
		case '+':
			_numbers.push(left + right);
			break;
		case '-':
			_numbers.push(left - right);
			break;
		case '*':
			_numbers.push(left * right);
			break;
		case '/':
			_numbers.push(left / right);
	}
}

RPN::Type RPN::findType(const char c)
{
	const std::string operators = "+-*/";
	
	if (c == ' ')
		return SPACE;
	else if (std::isdigit(static_cast<unsigned int>(c)))
		return NUMBER;
	else if (operators.find(c) != std::string::npos)
		return OPERATOR;
	else
		return UNKNOWN;
		
}

void RPN::pushNumber(const char c, int pos)
{
	if (pos % 2 == 1)
		throw std::runtime_error("Error");
		
	errno = 0;
	double num = std::strtod(&c, NULL);
	if (errno == ERANGE)
		throw std::overflow_error("Error");

	if (num < 0 || num > 9)
		throw std::range_error("Error");
	
	_numbers.push(num);
}

// 1 2 +
void RPN::calculate(const std::string& suite)
{
	const std::string operators = "+-*/";

	for (std::string::size_type i = 0; i < suite.length(); ++i)
	{
		switch(findType(suite[i]))
		{
			case NUMBER:
				pushNumber(suite[i], i);
				break;
			case OPERATOR:
				evaluate(suite[i], i);
				break;
			case SPACE:
				if (i % 2 == 0)
					throw std::runtime_error("Error");
				continue;
			case UNKNOWN:
				throw std::runtime_error("Error");
		}
	}
	if (_numbers.size() == 0 || _numbers.size() > 1)
		throw std::runtime_error("Error");
	std::cout << _numbers.top() << std::endl;
}