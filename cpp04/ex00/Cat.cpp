/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:21:26 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 12:15:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

const std::string Cat::TYPE = "Cat";

Cat::Cat() : Animal(TYPE)
{
	std::cout << "Cat Default Constructor called.\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor called.\n";
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Assignment Operator called.\n";
	_type = other._type;
	
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called.\n";
}

void Cat::makeSound(void) const
{
	std::cout << "MEOW MEOW MEOW\n";
}



