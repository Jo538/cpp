/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:30:30 by admin             #+#    #+#             */
/*   Updated: 2026/08/07 16:25:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	// DEFAULT CONSTRUCTOR TEST
	std::cout << "\033[1;32m----DEFAULT CONSTRUCTOR TEST----\033[0m\n";
	FragTrap player1;

	// NAME CONSTRUCTOR TEST
	std::cout << "\n\033[1;32m----NAME CONSTRUCTOR TEST----\033[0m\n";
	FragTrap player2("Yann");

	// COPY CONSTRUCTOR TEST
	std::cout << "\n\033[1;32m----COPY CONSTRUCTOR TEST----\033[0m\n";
	FragTrap player3(player1);

	// ASSIGNMENT OPERATOR TEST
	std::cout << "\n\033[1;32m----ASSIGNMENT OPERATOR TEST----\033[0m\n";
	player3 = player2;

	// HIGH FIVE() TEST
	std::cout << "\n\033[1;32m----HIGH FIVE() TEST----\033[0m\n";
	player2.highFiveGuys();
	std::cout << std::endl;
}