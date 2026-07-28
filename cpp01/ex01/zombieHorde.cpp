/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:53:01 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 15:58:26 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *newZombieHorde;

	newZombieHorde = new Zombie[N];

	for (int i=0; i < N; i++)
	{
		newZombieHorde[i].setIndex(i);
		newZombieHorde[i].setName(name);		
	}
	return newZombieHorde;
}