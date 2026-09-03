/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:09:01 by admin             #+#    #+#             */
/*   Updated: 2026/09/03 19:07:56 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
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
	{
		std::cerr << "Index is outside of bounds.\n";
		return ;
	}
	_idea[index] = idea;
}

//TODO: in case of error, what should I return for refs?
const std::string &Brain::getIdea(int index) const
{
	if (index < 0 || index >= IDEAS_COUNT)
	{
		std::cerr << "Index is outside of bounds.\n";
		return "";
	}
	return _idea[index];
}

