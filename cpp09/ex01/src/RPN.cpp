/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:21:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 18:30:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <iomanip>
#include "RPN.hpp"

void RPN::evaluate(const char c, int pos)
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Error");
	
	if (pos % 2 == 1)
		throw std::runtime_error("Error");

	double right = _numbers.top();
	
	if (c == '/' && right == 0)
		throw std::runtime_error("Error");

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
	else if (std::isdigit(static_cast<unsigned char>(c)))
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
		
	double num = c - '0';
	
	_numbers.push(num);
}

void RPN::calculate(const std::string& suite)
{
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
				if (i % 2 == 0 || (i == suite.length() - 1))
					throw std::runtime_error("Error");
				continue;
			case UNKNOWN:
				throw std::runtime_error("Error");
		}
	}
	if (_numbers.size() != 1)
		throw std::runtime_error("Error");

	std::cout << std::setprecision(std::numeric_limits<double>::digits10) << _numbers.top() << std::endl;
}