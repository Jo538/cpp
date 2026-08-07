/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:30:30 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 16:21:42 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// DEFAULT CONSTRUCTOR TEST
	std::cout << "\033[1;32m----DEFAULT CONSTRUCTOR TEST----\033[0m\n";
	ScavTrap player1;

	// NAME CONSTRUCTOR TEST
	std::cout << "\n\033[1;32m----NAME CONSTRUCTOR TEST----\033[0m\n";
	ScavTrap player2("Yann");

	// COPY CONSTRUCTOR TEST
	std::cout << "\n\033[1;32m----COPY CONSTRUCTOR TEST----\033[0m\n";
	ScavTrap player3(player1);

	// ASSIGNMENT OPERATOR TEST
	std::cout << "\n\033[1;32m----ASSIGNMENT OPERATOR TEST----\033[0m\n";
	player3 = player2;

	// ATTACK() TEST
	std::cout << "\n\033[1;32m----SCAVTRAP ATTACK() TEST----\033[0m\n";
	player2.attack("Jo");
	std::cout << std::endl;
}