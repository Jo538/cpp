#include <string>
#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "Please enter 1 of the 3 commands: ADD, SEARCH, EXIT\n";
	
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "EXIT")
			return (0);

		if (cmd == "ADD")
			phonebook.add_contact();

		if (cmd == "SEARCH")
			phonebook.print();
	}
}