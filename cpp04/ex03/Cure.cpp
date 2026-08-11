/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:09:19 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 19:18:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "color.h"
#include "AMateria.hpp"
#include "Cure.hpp"

const std::string Cure::TYPE = "cure";

Cure::Cure()
{
	std::cout << COLOR_YELLOW << "[Cure]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << COLOR_YELLOW << "[Cure]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << COLOR_YELLOW << "[Cure]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	// if (this != &other)
	// 	AMateria::operator=(other); copying the type doesn't make sense as will always be the same 
	return *this;
}

Cure::~Cure()
{
	std::cout << COLOR_YELLOW << "[Cure]" << COLOR_DEFAULT << ": Destructor called.\n";
}

AMateria *Cure::clone() const
{
	AMateria *newCure = new Cure(*this);
	return newCure;
}

void Cure::use(ICharacter &target)
{
	std::cout << COLOR_YELLOW << "[Cure]" << COLOR_DEFAULT << ": * heals " << target.getName() << "'s wounds *\n";
}	
