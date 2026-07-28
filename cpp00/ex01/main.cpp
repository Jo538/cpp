/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:39:12 by admin             #+#    #+#             */
/*   Updated: 2026/07/27 19:39:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string cmd;

	while (true)
	{
		std::cout << "Please enter 1 of the 3 commands: ADD, SEARCH, EXIT\n";
		if (!(std::cin >> cmd))
			return 1;
		std::cin.ignore(1, '\n');

		if (cmd == "EXIT")
			return (0);

		if (cmd == "ADD")
		{
			if (!phonebook.add_contact())
				return 1;
		}

		if (cmd == "SEARCH")
		{
			phonebook.print();
			phonebook.print_contact();
		}
	}
}