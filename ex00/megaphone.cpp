/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:27:48 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/27 15:31:54 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include <iostream>

void printUpper(const std::string &str)
{
	std::size_t i = 0;

	while (i < str.length())
	{
		char c = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
		std::cout << c;
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	argv++;
	while (*argv)
	{
		printUpper(*argv);
		argv++;
	}
	std::cout << "\n";
	return (0);
}
