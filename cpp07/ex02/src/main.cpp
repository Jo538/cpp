/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:23:51 by admin             #+#    #+#             */
/*   Updated: 2026/11/09 13:14:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <typeinfo>
#include "Array.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

int main(void)
{
	section(1, "Test canonical form on Array with INTS");
	Array<int> default_int;
	Array<int> spec_int(3);
	Array<int> copy_int(spec_int);
	default_int = spec_int;

	section(2, "Test canonical form on Array with STRINGS");
	Array<std::string> default_str;
	Array<std::string> spec_str(3);
	Array<std::string> copy_str(spec_str);
	default_str = spec_str;

	section(3, "Test deep copies vs shallow copies");
	spec_int.setArr(3);
	copy_int.setArr(3);
	std::cout << "Before: \nArray 1 --> " << spec_int << std::endl; 
	std::cout << "Array 2 --> " << copy_int << std::endl;
	spec_int.setArr(4);
	std::cout << "After: \nArray 1 --> " << spec_int << std::endl; 
	std::cout << "Array 2 --> " << copy_int << std::endl;	
	
	section(4, "Call Destructors");
}