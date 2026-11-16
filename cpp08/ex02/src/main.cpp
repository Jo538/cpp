/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:07:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/16 10:54:24 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

int main(void)
{
	section(1, "Call default constructor, MutantStack");
	
	MutantStack<int> a;
	MutantStack<std::string> b;

	section(2, "Populate stack & retrieve content");
	
	a.populateFromArr((int[]){42, 51, 99}, 3);
	a.printContainer();	

	b.populateFromArr((std::string[]){"Havana", "and", "Pollux"}, 3);
	b.printContainer();	

	section(3, "Call destructors");
}