/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:21:26 by admin             #+#    #+#             */
/*   Updated: 2026/08/09 13:20:50 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"
#include "color.h"

const std::string WrongCat::TYPE = "Dog";

WrongCat::WrongCat() : WrongAnimal(TYPE)
{
	std::cout << COLOR_RED << "[WrongCat]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << COLOR_RED << "[WrongCat]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << COLOR_RED << "[WrongCat]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	_type = other._type;
	
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << COLOR_RED << "[WrongCat]" << COLOR_DEFAULT << ": Destructor called.\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << COLOR_RED << "[WrongCat]" << COLOR_DEFAULT << ": MEOW MEOW MEOW\n";
}



