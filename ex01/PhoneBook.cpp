#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : index(0), fills(0) {} 

void PhoneBook::update_index()
{
	if (index == MAX_COUNT - 1)
		index = 0;
	else
		index++;
}

void PhoneBook::update_fills()
{
	if (fills < MAX_COUNT)
		fills++;
}

int PhoneBook::add_contact()
{
	if (contact[index].fill())
		return 1;
	update_index();
	update_fills();
	return 0;
}

static void print_cell(const std::string &cell)
{
	if (cell.length() > 10)
		std::cout << cell.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << cell;
}

void PhoneBook::print()
{
	int i = 0;

	while (i < fills)
	{
		std::cout << std::setw(10) << i << "|";
		print_cell(contact[i].getFirstName());
		std::cout << "|";
		print_cell(contact[i].getLastName());
		std::cout << "|";
		print_cell(contact[i].getNickname());
		std::cout << std::endl;
		i++;
	}

}

void PhoneBook::print_contact()
{
	int index;

	std::cout << "Enter index of the contact to display\n";
	std::cin >> index;
	std::cin.ignore(1, '\n');
	while (std::cin)
	{
		if (index < 0 || index >= fills)
		{
			std::cout << "Please enter a valid index\n";
			std::cin >> index;
			continue ;
		}
		std::cout << contact[index].getFirstName() << std::endl;
		std::cout << contact[index].getLastName() << std::endl;
		std::cout << contact[index].getNickname() << std::endl;
		std::cout << contact[index].getPhoneNumber() << std::endl;
		std::cout << contact[index].getDarkestSecret() << std::endl;
		break ;
	}
}

