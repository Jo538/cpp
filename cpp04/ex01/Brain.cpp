/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:09:01 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 12:10:48 by admin            ###   ########.fr       */
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
		idea[i] = other.idea[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << COLOR_GREEN << "[Brain]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	for (int i = 0; i < IDEAS_COUNT; i++)
		idea[i] = other.idea[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << COLOR_GREEN << "[Brain]" << COLOR_DEFAULT << ": Destructor called.\n";
}

