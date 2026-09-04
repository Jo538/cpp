/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:21:26 by admin             #+#    #+#             */
/*   Updated: 2026/09/04 12:58:25 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"
#include "color.h"

const std::string WrongCat::TYPE = "Wrong cat";

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



