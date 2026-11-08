/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:23:51 by admin             #+#    #+#             */
/*   Updated: 2026/11/08 14:10:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

int main(void)
{
	section(1, "Test with array of INTS");
	::iter((int[3]){1, 2, 3}, 3, printValue);

	section(2, "Test with array of CONST INTS");
	::iter((const int[3]){1, 2, 3}, 3, printValue);

	section(3, "Test with array of STRINGS");
	::iter((std::string[3]){"Havana", "and", "Pollux"}, 3, printValue);
}