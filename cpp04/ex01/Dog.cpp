/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:24:32 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 17:58:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "color.h"

const std::string Dog::TYPE = "Dog";

Dog::Dog() : Animal(TYPE)
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Default Constructor called.\n";	
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Copy Constructor called.\n";	
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Assignment Operator called.\n";	
	Animal::operator=(other);
	*_brain = *other._brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": Destructor called.\n";	
	delete _brain;
}

void Dog::makeSound(void) const
{
	std::cout << COLOR_MAGENTA << "[Dog]" << COLOR_DEFAULT << ": WAF WAF WAF\n";
}

const std::string &Dog::getIdea(unsigned int index) const
{
	return _brain->getIdea(index);
}

void Dog::setIdea(std::string idea, unsigned int index)
{
	_brain->setIdea(idea, index);
}
