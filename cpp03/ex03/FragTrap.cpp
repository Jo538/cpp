/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:53:43 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 13:46:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const size_t FragTrap::HIT_POINTS;
const size_t FragTrap::ENERGY_POINTS;
const size_t FragTrap::ATTACK_DAMAGE;

FragTrap::FragTrap() : ClapTrap("Default", HIT_POINTS, ENERGY_POINTS, ATTACK_DAMAGE)
{
	std::cout << "FragTrap Default constructor called.\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, HIT_POINTS, ENERGY_POINTS, ATTACK_DAMAGE)
{
	std::cout << "FragTrap Name constructor called.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Assignment Operator called.\n";
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called.\n";	
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}