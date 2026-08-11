/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:10:28 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 15:33:59 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "color.h"

const std::string Animal::DEFAULT_TYPE = "Random Animal";

Animal::Animal() : _type(DEFAULT_TYPE)
{
	std::cout << COLOR_BLUE << "[Animal]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << COLOR_BLUE << "[Animal]" << COLOR_DEFAULT << ": Type Constructor called.\n";	
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << COLOR_BLUE << "[Animal]" << COLOR_DEFAULT << ": Copy Constructor called.\n";	
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << COLOR_BLUE << "[Animal]" << COLOR_DEFAULT << ": Assignment Operator called.\n";	
	_type = other._type;
	
	return *this;
}

Animal::~Animal()
{
	std::cout << COLOR_BLUE << "[Animal]" << COLOR_DEFAULT << ": Destructor called.\n";	
}

const std::string &Animal::getType(void) const
{
	return _type;
}
