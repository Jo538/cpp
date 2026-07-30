/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:32:33 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/30 10:46:44 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my" 
			  << "7XL-double-cheese-triple-pickle-special-"
			  << "ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs"
			  << "more money. You didn’t put enough bacon in"
			  << "my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon"
			  << "for free. I’ve been coming for years, whereas"
			  << "you started working here just last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now. \n";
}

void Harl::complain(std::string level)
{
	std::string word[WORD_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < WORD_COUNT; i++)
	{
		if (word[i] == level)
		{
			(this->*function[i])();
			return ;			
		}
	}
}