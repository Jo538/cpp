/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:03:56 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/30 17:24:13 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) { }

HumanA::~HumanA() { }

void HumanA::attack() const
{
	std::cout << _name
	          << " attacks with their "
			  << _weapon.getType() << std::endl;
}
