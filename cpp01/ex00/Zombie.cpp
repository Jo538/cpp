/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:31:43 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/30 17:00:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinzzzZ...\n"; 
}

Zombie::Zombie( std::string name ) : _name(name) { }

Zombie::~Zombie( void )
{
	std::cout << _name << ": Zombie is dead.\n";
}