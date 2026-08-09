/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:24:32 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 12:15:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

const std::string Dog::TYPE = "Dog";

Dog::Dog() : Animal(TYPE)
{
	std::cout << "Dog Default Constructor called.\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor called.\n";
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignment Operator called.\n";
	_type = other._type;
	
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called.\n";
}

void Dog::makeSound(void) const
{
	std::cout << "WAF WAF WAF\n";
}


