/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:20:08 by admin             #+#    #+#             */
/*   Updated: 2026/08/06 18:29:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20), _is_guarded(false)
{ 
	std::cout << "ScavTrap Default constructor called.\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20), _is_guarded(false)
{
	std::cout << "ScavTrap Name constructor called.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _is_guarded(other._is_guarded)
{
	std::cout << "ScavTrap Copy constructor called.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	_is_guarded = other._is_guarded;
	std::cout << "ScavTrap Copy Assignment operator called.\n";
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called.\n";
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "[SCAVTRAP]: ";
	
	if (!_hitPoints)
		std::cout << _name << " can't attack " << target
		    	  << " as it has 0 hit points." << std::endl;
	else if (!_energyPoints)
	{
		std::cout << _name << " can't attack " << target
				  << " as it has 0 energy points." << std::endl;
		return ;
	}
	else 
	{
		std::cout << _name << " attacks " << target
				  << ", causing " << _attackDamage << " points of damage!" << std::endl;

		_energyPoints-=1;		
	}
}

void ScavTrap::guardGate()
{
	if (!_is_guarded)
	{
		_is_guarded = true;
		std::cout << "ScavTrap changed to Gate keeper mode.\n";		
	}
	else if (_is_guarded)
		std::cout << "ScavTrap is already in Gate keeper mode, no change done.\n";		
}
