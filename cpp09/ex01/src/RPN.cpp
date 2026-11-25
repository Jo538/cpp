/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:21:38 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 14:01:06 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

// 1 2 +
// Traverse operation 1 character at a time
// Recognise digit from operator
// if digit --> push to stack
// if operator --> pop 2 times --> calculate --> push result to stack
// Repeat
void RPN::calculate(const std::string& operation)
{
	double right = 0;
	double left = 0;

	for (std::string::size_type i = 0; i < operation.length(); ++i)
	{
		if (std::isdigit(static_cast<unsigned int>(operation[i])))
			_numbers.push(std::atoi(&operation[i]));
		if (operation[i] == '+')
		{
			right = _numbers.top();
			_numbers.pop();
			left = _numbers.top();
			_numbers.pop();
			_numbers.push(right + left);
		}
	}
	std::cout << _numbers.top() << std::endl;
}