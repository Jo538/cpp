/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:11:34 by admin             #+#    #+#             */
/*   Updated: 2026/08/06 18:06:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	// Data Members
	std::string _name;
	size_t _hitPoints;
	size_t _energyPoints;
	size_t _attackDamage; 

	// Constructor
	ClapTrap(const std::string name, size_t hitPoints, size_t energyPoints, size_t attackDamage);
public:
	// Constructors
	ClapTrap();
	ClapTrap(const std::string name);

	// Copy Constructor
	ClapTrap(const ClapTrap &other);

	// Destructor
	~ClapTrap();

	// Overloaded operator
	ClapTrap &operator=(const ClapTrap &other);

	// Getters
	const std::string &getName() const;
	size_t getHitPoints() const;
	size_t getEnergyPoints() const;	
	size_t getAttackDamage() const;
				
	// Member Functions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

	std::ostream &operator<<(std::ostream &os, const ClapTrap &other);
	
#endif