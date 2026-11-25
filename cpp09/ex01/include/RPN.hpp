/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:16:08 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 16:10:23 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
public:
	RPN() {};
	RPN(const RPN& other) : _numbers(other._numbers) {};
	RPN& operator=(const RPN& other) {_numbers = other._numbers; return *this;};
	~RPN() {};

	void calculate(const std::string& operation);

private:
	std::stack<double> _numbers;

	void evaluate(const char c);
};

#endif