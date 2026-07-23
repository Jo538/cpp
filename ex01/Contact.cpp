#include "Contact.hpp"

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkestSecret() const { return darkest_secret; }

static void fill_cell(std::string &cell)
{
	while (1)
	{
		std::getline(std::cin, cell);
		if (cell.empty())
		{
			std::cout << "Enter valid contact info\n";
			continue ;
		}
		break ;		
	}
}

void Contact::fill()
{
	std::cout << "First name: ";
	fill_cell(first_name);

	std::cout << "Last name: ";
	fill_cell(last_name);
	
	std::cout << "Nickname: ";
	fill_cell(nickname);
	
	std::cout << "Phone number: ";
	fill_cell(phone_number);
	
	std::cout << "Darkest secret: ";
	fill_cell(darkest_secret);
}