/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:45:01 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 15:35:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name", FragTrap::HIT_POINTS, ScavTrap::ENERGY_POINTS, FragTrap::ATTACK_DAMAGE), ScavTrap(), FragTrap(), _name("Default")
{
	std::cout << "DiamondTrap Default constructor called.\n";	
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name", FragTrap::HIT_POINTS, ScavTrap::ENERGY_POINTS, FragTrap::ATTACK_DAMAGE), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap Name constructor called.\n";	
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called.\n";	
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Assignment Operator called.\n";
	_name = other._name;

	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called.\n";	
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}