/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:51:53 by admin             #+#    #+#             */
/*   Updated: 2026/11/11 19:27:28 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

static void test(char c, unsigned int max, std::string set_status)
{
	std::cout << "\n" << BOLD << "▸ Span " << c
	<< " - max = " << max << ", set " << set_status << COLOR_DEFAULT << std::endl;
}

int main(void)
{
	section(1, "Call Constructors");
	
	test('a', 10, "empty");
	Span a;
	
	test('b', 100, "empty");
	Span b(100);
	
	test('c', 100, "empty");
	Span c(b);

	section(2, "Call Destructors");
}