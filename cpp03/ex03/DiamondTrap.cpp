/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:45:01 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 13:23:29 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(ClapTrap::_name, FragTrap::HIT_POINTS, ScavTrap::ENERGY_POINTS, FragTrap::ATTACK_DAMAGE), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called.\n";	
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name, FragTrap::HIT_POINTS, ScavTrap::ENERGY_POINTS, FragTrap::ATTACK_DAMAGE), ScavTrap(), FragTrap()
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
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	
	return *this;
}