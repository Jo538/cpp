/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:21:26 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 13:03:41 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "color.h"

const std::string Cat::TYPE = "Cat";

Cat::Cat() : Animal(TYPE)
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Default Constructor called.\n";	
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Copy Constructor called.\n";	
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Assignment Operator called.\n";	
	_type = other._type;
	
	return *this;
}

Cat::~Cat()
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Destructor called.\n";	
}

void Cat::makeSound(void) const
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": MEOW MEOW MEOW\n";
}



