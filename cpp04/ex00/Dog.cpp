/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:24:32 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 13:03:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "color.h"

const std::string Dog::TYPE = "Dog";

Dog::Dog() : Animal(TYPE)
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Default Constructor called.\n";	
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Copy Constructor called.\n";	
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Assignment Operator called.\n";	
	_type = other._type;
	
	return *this;
}

Dog::~Dog()
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Destructor called.\n";	
}

void Dog::makeSound(void) const
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": WAF WAF WAF\n";
}


