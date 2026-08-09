/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:10:28 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 12:14:47 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

const std::string Animal::DEFAULT_TYPE = "Random Animal";

Animal::Animal() : _type(DEFAULT_TYPE)
{
	std::cout << "Animal Default Constructor called.\n";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal Type Constructor called.\n";	
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal Copy Constructor called.\n";
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal Assignment Operator called.\n";
	_type = other._type;
	
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called.\n";
}

const std::string &Animal::getType(void) const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout << "Random Animal sound.\n";
}



