#include "Contact.hpp"

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }

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