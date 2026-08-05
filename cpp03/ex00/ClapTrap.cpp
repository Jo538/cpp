/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:21:13 by admin             #+#    #+#             */
/*   Updated: 2026/08/05 15:59:39 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{ 
	std::cout << "ClapTrap Default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "ClapTrap Name constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) 
{
	std::cout << "ClapTrap Copy constructor called.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
	std::cout << "ClapTrap Copy Assignment operator called.\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap Destructor called.\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (!_hitPoints)
		std::cout << _name << " can't attack " << target
		    	  << " as it has 0 hit points." << std::endl;
	if (!_energyPoints)
	{
		std::cout << _name << " can't attack " << target
				  << " as it has 0 energy points." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;

	_energyPoints-=1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints && amount)
		std::cout << _name << " can't be attacked as it is already dead." << std::endl;
	else if (amount > _hitPoints)
	{
		std::cout << _name << " can only take " << amount << " of damage as it has only " << _hitPoints << " hit points." << std::endl;
		_hitPoints = 0;	
	}
	else 
	{
		_hitPoints-=amount;	
		std::cout << _name << " took " << amount << " points of damage and has " << _hitPoints << " hit points left." << std::endl;	
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
		std::cout << _name << " can't be repaired as it is already dead." << std::endl;

	if (!_energyPoints)
		std::cout << _name << " can't be repaired as it has 0 energy points left." << std::endl;
	else
	{
		_hitPoints+=amount;
		_energyPoints-=1;
		std::cout << _name << " regained " << amount << " hit points. It now has " << _hitPoints << " hit points and " << _energyPoints << " energy points left." << std::endl;
	}
}

const std::string &ClapTrap::getName() const
{
	return _name;
}


std::ostream &operator<<(std::ostream &os, const ClapTrap &other)
{
	os << other.getName();
	return (os);
}