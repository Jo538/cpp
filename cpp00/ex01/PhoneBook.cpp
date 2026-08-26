/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:39:19 by admin             #+#    #+#             */
/*   Updated: 2026/08/26 10:34:30 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : index(0), fills(0) {} 

void PhoneBook::update_fills()
{
	if (fills < MAX_COUNT)
		fills++;
}

bool PhoneBook::add_contact()
{
	if (!contact[index].fill())
		return false;
	index = (index + 1) % MAX_COUNT;
	update_fills();
	return true;
}

static void print_cell(const std::string &cell, long unsigned int col_width)
{
	if (cell.length() > col_width)
		std::cout << cell.substr(0, col_width - 1) + ".";
	else
		std::cout << std::setw(col_width) << cell;
}

void PhoneBook::print()
{
	int i = 0;

	while (i < fills)
	{
		std::cout << std::setw(COL_WIDTH) << i << "|";
		print_cell(contact[i].getFirstName(), COL_WIDTH);
		std::cout << "|";
		print_cell(contact[i].getLastName(), COL_WIDTH);
		std::cout << "|";
		print_cell(contact[i].getNickname(), COL_WIDTH);
		std::cout << std::endl;
		i++;
	}

}

void PhoneBook::print_contact()
{
	int i = -1;
	while (std::cin)
	{
		std::cout << "Enter index of the contact to display\n";
		std::cin >> i;
		std::cin.ignore(1, '\n');
		if (i < 0 || i >= fills)
			continue ;
		std::cout << contact[i].getFirstName() << std::endl;
		std::cout << contact[i].getLastName() << std::endl;
		std::cout << contact[i].getNickname() << std::endl;
		std::cout << contact[i].getPhoneNumber() << std::endl;
		std::cout << contact[i].getDarkestSecret() << std::endl;
		break ;
	}
}

