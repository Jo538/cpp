/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:30:30 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 15:46:15 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
	// Constructor tests
	std::cout << "\033[1;32m----DEFAULT CONSTRUCTOR TEST----\033[0m\n";
	DiamondTrap player1;
	std::cout << "\n\033[1;32m----NAME CONSTRUCTOR TEST----\033[0m\n";
	DiamondTrap player2("Yann");
	std::cout << "\n\033[1;32m----COPY CONSTRUCTOR TEST----\033[0m\n";
	DiamondTrap player3 = player1;
	
	// Assignment Operator test
	std::cout << "\n\033[1;32m----ASSIGNMENT OPERATOR TEST----\033[0m\n";
	player3 = player2;

	// Data members test
	std::cout << "\n\033[1;32m----DATA MEMBERS TEST----\033[0m\n";
	std::cout << player1;

	// Attack() test
	std::cout << "\n\033[1;32m----ATTACK() TEST----\033[0m\n";
	player2.attack("Jo");
	std::cout << std::endl;

	// WhoAmI() test
	std::cout << "\n\033[1;32m----WHOAMI() TEST----\033[0m\n";
	player3.whoAmI();
	std::cout << std::endl;
}