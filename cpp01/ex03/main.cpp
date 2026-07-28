/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:34:24 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 17:38:50 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");
	std::cout << club.getType() << std::endl;
	club.setType("another club");
	std::cout << club.getType() << std::endl;	
}