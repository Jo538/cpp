/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:31:43 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 10:56:25 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinzzzZ...\n"; 
}

Zombie::Zombie( std::string name )
{
	Zombie::name = name;
}

Zombie::~Zombie( void )
{
	std::cout << name << ": Zombie is dead.\n";
}