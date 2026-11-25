/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:16:08 by admin             #+#    #+#             */
/*   Updated: 2026/11/25 18:21:20 by admin            ###   ########.fr       */
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

	void calculate(const std::string& suite);

private:
	enum Type {NUMBER, OPERATOR, SPACE, UNKNOWN};
	
	std::stack<double> _numbers;

	void evaluate(const char c, int pos);
	void pushNumber(const char c, int pos);
	static Type findType(const char c);
};

#endif