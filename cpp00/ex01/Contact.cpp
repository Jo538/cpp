/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:38:50 by admin             #+#    #+#             */
/*   Updated: 2026/07/27 19:38:52 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

const std::string &Contact::getFirstName() const { return first_name; }
const std::string &Contact::getLastName() const { return last_name; }
const std::string &Contact::getNickname() const { return nickname; }
const std::string &Contact::getPhoneNumber() const { return phone_number; }
const std::string &Contact::getDarkestSecret() const { return darkest_secret; }

static bool fill_cell(std::string &cell)
{
	while (true)
	{
		if(!std::getline(std::cin, cell))
			return false;
		if (cell.empty())
		{
			std::cout << "Enter valid contact info\n";
			continue ;
		}
		break ;		
	}
	return true;
}

bool Contact::fill()
{
	int i = 0;
	std::string prompts[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
	std::string *fields[5] = {&first_name, &last_name, &nickname, &phone_number, &darkest_secret};

	while (i < 5)
	{
		std::cout << prompts[i];
		if (!fill_cell(*fields[i]))
			return false;
		i++;
	}
	return true;
}