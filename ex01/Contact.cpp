#include "Contact.hpp"

void Contact::print()
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;	
}

void Contact::fill()
{
	std::cout << "First name: ";
	std::cin >> first_name;

	std::cout << "Last name: ";
	std::cin >> last_name;

	std::cout << "Nickname: ";
	std::cin >> nickname;

	std::cout << "Phone number: ";
	std::cin >> phone_number;

	std::cout << "Darkest secret: ";
	std::cin >> darkest_secret;	
}