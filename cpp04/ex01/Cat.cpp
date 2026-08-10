/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:21:26 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 17:30:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"
#include "color.h"

const std::string Cat::TYPE = "Cat";

Cat::Cat() : Animal(TYPE)
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Default Constructor called.\n";	
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Assignment Operator called.\n";	
	
	Animal::operator=(other);
	*_brain = *other._brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": Destructor called.\n";
	delete _brain;	
}

void Cat::makeSound(void) const
{
	std::cout << COLOR_YELLOW << "[Cat]" << COLOR_DEFAULT << ": MEOW MEOW MEOW\n";
}

const std::string &Cat::getIdea(unsigned int index) const
{
	return _brain->getIdea(index);
}

void Cat::setIdea(std::string idea, unsigned int index)
{
	_brain->setIdea(idea, index);
}

