/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:32:33 by jchartie          #+#    #+#             */
/*   Updated: 2026/08/26 18:08:24 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my" 
			  << "7XL-double-cheese-triple-pickle-special-"
			  << "ketchup burger. I really do!\n\n";
}

void Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs"
			  << "more money. You didn’t put enough bacon in"
			  << "my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon"
			  << "for free. I’ve been coming for years, whereas"
			  << "you started working here just last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
	std::string word[WORD_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i;
	for (i = 0; i < WORD_COUNT; i++)
	{
		if (word[i] == level)
			break ;
	}

	switch (i)
	{
		case 0:
			(this->*function[0])();
			// fallthrough
		case 1:
			(this->*function[1])();
			// fallthrough
		case 2:
			(this->*function[2])();
			// fallthrough
		case 3:
			(this->*function[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}