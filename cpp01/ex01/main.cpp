/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:26:20 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 15:58:50 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	zombie = zombieHorde(5, "Jo");
	
	for (int i = 0; i < 5; i++)
		zombie[i].announce();
	
	delete[] zombie;
	return 0;
}