/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:27:48 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/27 11:45:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include <iostream>

int touppercase(const std::string &str)
{
	std::size_t i = 0;

	while (i < str.length())
	{
		char c = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
		std::cout << c;
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	argv++;
	while (*argv)
	{
		touppercase(*argv);
		argv++;
	}
	std::cout << "\n";
	return (0);
}
