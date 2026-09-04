/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:09:01 by admin             #+#    #+#             */
/*   Updated: 2026/09/04 11:10:45 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include <stdexcept>
#include "color.h"

const int Brain::IDEAS_COUNT;

Brain::Brain()
{
	std::cout << COLOR_GREEN << "[Brain]" << COLOR_DEFAULT << ": Default constructor called.\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << COLOR_GREEN << "[Brain]" << COLOR_DEFAULT << ": Copy constructor called.\n";
	for (int i = 0; i < IDEAS_COUNT; i++)
		_idea[i] = other._idea[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << COLOR_GREEN << "[Brain]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	if (this == &other)
		return *this;
	for (int i = 0; i < IDEAS_COUNT; i++)
		_idea[i] = other._idea[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << COLOR_GREEN << "[Brain]" << COLOR_DEFAULT << ": Destructor called.\n";
}

void Brain::setIdea(std::string &idea, int index)
{
	if (index < 0 || index >= IDEAS_COUNT)
		throw std::out_of_range("Brain::setIdea: index is out of bounds");
	_idea[index] = idea;
}

// TODO: why does the parameter inside getIdea need to be a ref and can't be passed by value?
const std::string &Brain::getIdea(int index) const
{
	if (index < 0 || index >= IDEAS_COUNT)
		throw std::out_of_range("Brain::getIdea: index is out of bounds");
	return _idea[index];			
}
