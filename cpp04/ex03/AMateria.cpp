/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:56:17 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 16:03:59 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "color.h"
#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << COLOR_BLUE << "[AMateria]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << COLOR_BLUE << "[AMateria]" << COLOR_DEFAULT << ": Type Constructor called.\n";
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << COLOR_BLUE << "[AMateria]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << COLOR_BLUE << "[AMateria]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << COLOR_BLUE << "[AMateria]" << COLOR_DEFAULT << ": Destructor called.\n";
}