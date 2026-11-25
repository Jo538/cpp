/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:21:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 16:44:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

// 1 - --> 1 number and 1 operator or more
// 1 2 - - --> 2 numbers and 2 operators or more

void RPN::evaluate(const char c)
{
	if (!isValidOperation())
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

bool RPN::isValidOperation() const
{
	if (_numbers.size() == 1)
		return false;
	return true;
}

// 1
void RPN::calculate(const std::string& operation)
{
	const std::string operators = "+-*/";

	for (std::string::size_type i = 0; i < operation.length(); ++i)
	{
		if (std::isdigit(static_cast<unsigned int>(operation[i])))
			_numbers.push(std::strtod(&operation[i], NULL));
		
		if (operators.find(operation[i]) != std::string::npos)
			evaluate(operation[i]);

	}
	std::cout << _numbers.top() << std::endl;
}