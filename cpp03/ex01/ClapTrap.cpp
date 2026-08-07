/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:21:13 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 16:16:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

const size_t ClapTrap::HIT_POINTS;
const size_t ClapTrap::ENERGY_POINTS;
const size_t ClapTrap::ATTACK_DAMAGE;

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(HIT_POINTS), _energyPoints(ENERGY_POINTS), _attackDamage(ATTACK_DAMAGE) 
{ 
	std::cout << "ClapTrap Default constructor called.\n";
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(HIT_POINTS), _energyPoints(ENERGY_POINTS), _attackDamage(ATTACK_DAMAGE) 
{
	std::cout << "ClapTrap Name constructor called.\n";
}

ClapTrap::ClapTrap(const std::string name, size_t hitPoints, size_t energyPoints, size_t attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) 
{
	std::cout << "ClapTrap Extended Init constructor called.\n";
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
	std::cout << "[CLAPTRAP]: ";

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
	else if (!_energyPoints)
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

size_t ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

size_t ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

size_t ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}


std::ostream &operator<<(std::ostream &os, const ClapTrap &other)
{
	os << "Name: " << other.getName() << std::endl
	   << "Hit Points: " << other.getHitPoints() << std::endl
	   << "Energy Points: " << other.getEnergyPoints() << std::endl
	   << "Attack Damage: " << other.getAttackDamage() << std::endl;

	return (os);
}