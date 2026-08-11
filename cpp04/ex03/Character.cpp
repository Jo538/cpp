/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 18:03:25 by admin             #+#    #+#             */
/*   Updated: 2026/08/11 19:27:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "color.h"

const unsigned int SIZE_INVENTORY;

Character::Character() : _name("Default"), _inventory()
{
	std::cout << COLOR_GREEN << "[Character]" << COLOR_DEFAULT << ": Default Constructor called.\n";
}

Character::Character(std::string const name) : _name(name), _inventory()
{
	std::cout << COLOR_GREEN << "[Character]" << COLOR_DEFAULT << ": Type Constructor called.\n";
}

Character::Character(const Character &other) : _name(other._name)
{
	std::cout << COLOR_GREEN << "[Character]" << COLOR_DEFAULT << ": Copy Constructor called.\n";
	for (int i = 0; i < SIZE_INVENTORY; i++)
		_inventory[i] = other._inventory[i]->clone();
}

Character &Character::operator=(const Character &other)
{
	std::cout << COLOR_GREEN << "[Character]" << COLOR_DEFAULT << ": Assignment Operator called.\n";
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < SIZE_INVENTORY; i++)
			*_inventory[i] = *other._inventory[i];
	}
	return *this;
}

Character::~Character()
{
	std::cout << COLOR_GREEN << "[Character]" << COLOR_DEFAULT << ": Destructor called.\n";
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < SIZE_INVENTORY; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter& target)
{
	
}
