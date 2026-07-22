#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {} 

void PhoneBook::update_index()
{
	if (index == MAX_COUNT - 1)
		index = 0;
	else
		index++;
}

void PhoneBook::add_contact()
{
	contact[index].fill();
	update_index();
}