/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:27:52 by admin             #+#    #+#             */
/*   Updated: 2026/11/12 19:24:07 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "Span.hpp"

unsigned int Span::DEFAULT_MAX = 10;

Span::Span() : max(DEFAULT_MAX)
{
	std::cout << "[Span] Default Constructor called" << std::endl;
}

Span::Span(unsigned int num) : max(num)
{
	std::cout << "[Span] Spec Constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "[Span] Destructor called" << std::endl;
}

Span::Span(const Span& other) : max(other.max), set(other.set)
{
	std::cout << "[Span] Copy Constructor called" << std::endl;	
}

Span& Span::operator=(const Span& other)
{
	std::cout << "[Span] Copy Assignment Operator called" << std::endl;	
	this->max = other.max;
	this->set = other.set;
	return *this;
}

unsigned int Span::getMax() const
{
	return this->max;
}

size_t Span::getSetSize() const
{
	return this->set.size();
}

void Span::addNumber(int num)
{
	if (this->set.size() == this->max)
		throw std::out_of_range("Error: max number of ints reached");
	this->set.insert(num);
}

const std::multiset<int>& Span::getSet() const
{
	return this->set;
}

int Span::longestSpan()
{
	if (this->set.empty() || (this->set.size() == 1))
		throw std::logic_error("Error: set is empty or has only 1 element");
	int min = *(this->set.begin());
	int max = *(--this->set.end());
	
	return (std::abs(max - min));
}

int Span::shortestSpan()
{
	int min = this->longestSpan();
	
	std::multiset<int>::const_iterator current = this->set.begin();
	std::multiset<int>::const_iterator next = current;
	++next;
	
	for (; next != this->set.end(); ++current, ++next)
	{
		if ((*next - *current) < min)
			min = (*next - *current);
	}
	return min;
}

std::ostream& operator<<(std::ostream& os, const Span& object)
{
	const std::multiset<int>& set = object.getSet();
	if (set.empty())
		return os << "empty";
	const int* last_it  = &*(--set.end());
	
	for (std::multiset<int>::const_iterator it = set.begin(); it != set.end(); ++it)
	{
		os << *it;
		if (&*it != last_it)
			os << " ";		
	}
	return os;
}