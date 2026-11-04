/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:16:12 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 16:49:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"
#include "Serializer.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

int main(void)
{
	section(1, "Instantiate a Data object");
	Data dog;
	Data *ptr = &dog;

	std::cout << "name: " << ptr->getName() << std::endl;
	std::cout << "breed: " << ptr->getBreed() << std::endl;
	std::cout << "age: " << ptr->getAge() << std::endl;

	section(2, "Serialize and Deserialize a Data* ptr");
	
	uintptr_t ser_ptr = Serializer::serialize(ptr);
	Data* deser_ptr = Serializer::deserialize(ser_ptr);

	std::cout << (deser_ptr == ptr ? COLOR_GREEN "✔ PASS" : COLOR_RED "✘ FAIL") << COLOR_DEFAULT << std::endl;
	std::cout << "Initial Data*: " << ptr << std::endl;
	std::cout << "Desrialized Data*: " << deser_ptr << std::endl;

	section(3, "Call Destructor local Data object");
	return 0;
}