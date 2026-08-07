/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:30:30 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 16:13:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	// DEFAULT CONSTRUCTOR TEST
	std::cout << "\033[1;32m----DEFAULT CONSTRUCTOR TEST----\033[0m\n";
	ClapTrap player1;

	// NAME CONSTRUCTOR TEST
	std::cout << "\n\033[1;32m----NAME CONSTRUCTOR TEST----\033[0m\n";
	ClapTrap player2("Yann");

	// COPY CONSTRUCTOR TEST
	std::cout << "\n\033[1;32m----COPY CONSTRUCTOR TEST----\033[0m\n";
	ClapTrap player3(player1);

	// ATTACK() TEST
	std::cout << "\n\033[1;32m----ATTACK() TEST----\033[0m\n";
	player1.attack("Yann");

	// TAKE DAMAGE() TEST
	std::cout << "\n\033[1;32m----TAKE DAMAGE() TEST----\033[0m\n";
	player2.takeDamage(2);

	// BE REPAIRED() TEST
	std::cout << "\n\033[1;32m----BE REPAIRED() TEST----\033[0m\n";
	player2.beRepaired(1);
	std::cout << std::endl;
}