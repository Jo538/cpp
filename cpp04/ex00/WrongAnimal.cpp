/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:10:28 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 13:11:46 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"
#include "color.h"

const std::string WrongAnimal::DEFAULT_TYPE = "Random Animal";

WrongAnimal::WrongAnimal() : _type(DEFAULT_TYPE)
{
	std::cout << COLOR_GREEN << "[WrongAnimal]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << COLOR_GREEN << "[WrongAnimal]" << COLOR_DEFAULT << ": Type Constructor called.\n";	
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << COLOR_GREEN << "[WrongAnimal]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << COLOR_GREEN << "[WrongAnimal]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	_type = other._type;
	
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << COLOR_GREEN << "[WrongAnimal]" << COLOR_DEFAULT << ": Destructor called.\n";
}

const std::string &WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << COLOR_GREEN << "[WrongAnimal]" << COLOR_DEFAULT << ": Random Animal Sound.\n";
}



