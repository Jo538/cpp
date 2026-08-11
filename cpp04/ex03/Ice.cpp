/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:53:26 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 19:18:25 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "color.h"
#include "AMateria.hpp"
#include "Ice.hpp"

const std::string Ice::TYPE = "ice";

Ice::Ice() : AMateria("Default")
{
	std::cout << COLOR_MAGENTA << "[Ice]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << COLOR_MAGENTA << "[Ice]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << COLOR_MAGENTA << "[Ice]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	// if (this != &other)
	// 	AMateria::operator=(other); copying the type doesn't make sense as will always be the same 
	return *this;
}

Ice::~Ice()
{
	std::cout << COLOR_MAGENTA << "[Ice]" << COLOR_DEFAULT << ": Destructor called.\n";
}

AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice(*this);
	return newIce;
}

void Ice::use(ICharacter &target)
{
	std::cout << COLOR_MAGENTA << "[Ice]" << COLOR_DEFAULT << ": * shoots an ice bolt at " << target.getName() << " *\n";
}	