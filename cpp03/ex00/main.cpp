/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:30:30 by admin             #+#    #+#             */
/*   Updated: 2026/08/05 15:57:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap player1;
	ClapTrap player2("Yann");
	ClapTrap player3(player1);

	std::cout << "Name of player1: " << player1 << std::endl;
	std::cout << "Name of player2: " << player2 << std::endl;
	std::cout << "Name of player3: " << player3 << std::endl;

	player3 = ClapTrap("Jo");
	std::cout << "Name of player3: " << player3 << std::endl;

	player1.attack("Yann");
	player2.takeDamage(2);
	player2.beRepaired(1);
}