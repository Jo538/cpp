/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:21:26 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 12:43:25 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

const std::string WrongCat::TYPE = "Dog";

WrongCat::WrongCat() : WrongAnimal(TYPE)
{
	std::cout << "WrongCat Default Constructor called.\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy Constructor called.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat Assignment Operator called.\n";
	_type = other._type;
	
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called.\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "WAF WAF WAF\n";
}



