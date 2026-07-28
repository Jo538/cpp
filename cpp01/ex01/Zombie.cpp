/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:03:03 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 16:03:18 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() { }

Zombie::~Zombie()
{
	std::cout << _index << ": " 
			  << _name << ": Zombie is dead.\n";	
}

void Zombie::announce( void ) const
{
	std::cout << _index << ": " << _name 
			  << ": BraiiiiiiinzzzZ...\n"; 
}

void Zombie::setName(std::string name)
{
	_name = name; 
}

void Zombie::setIndex(int index)
{
	_index = index;
}