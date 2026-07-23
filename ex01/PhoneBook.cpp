#include "PhoneBook.hpp"

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

void PhoneBook::add_contact()
{
	contact[index].fill();
	update_index();
	update_fills();
}

void PhoneBook::print()
{
	int i = 0;
	std::string str;

	while (i < fills)
	{
		std::cout << std::setw(10) << i << "|";
		if (contact[i].getFirstName().length() > 10)
			std::cout << (str = contact[i].getFirstName().substr(0, 9) + ".");
		else
			std::cout << std::setw(10) <<  contact[i].getFirstName();
		std::cout << "|";
		if (contact[i].getLastName().length() > 10)
			std::cout << (str = contact[i].getLastName().substr(0, 9) + ".");
		else
			std::cout << std::setw(10) <<  contact[i].getLastName();
		std::cout << "|";
		if (contact[i].getNickname().length() > 10)
			std::cout << (str = contact[i].getNickname().substr(0, 9) + ".") << std::endl;
		else
			std::cout << std::setw(10) <<  contact[i].getNickname() << std::endl;
		i++;
	}

}

