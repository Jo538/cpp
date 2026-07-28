/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:03:56 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 17:23:50 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	_name = name;
	_weapon = weapon;
}

void HumanA::attack() const
{
	std::cout << _name
	          << " attachs with their "
			  << _weapon.getType() << std::endl;
}
