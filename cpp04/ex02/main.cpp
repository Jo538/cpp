/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:46:31 by admin             #+#    #+#             */
/*   Updated: 2026/09/04 12:50:51 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "color.h"

int main(void)
{
	const int count = 4;
	std::cout << BOLD << "----DEFAULT CONSTRUCTOR TESTS FOR AN ARRAY OF CATS & DOGS----\n" << COLOR_DEFAULT;
	Animal *animal[count];
	
	for (int i = 0; i < (count / 2); i++)
		animal[i] = new Dog();
	for (int i = (count / 2); i < count; i++)
		animal[i] = new Cat();

	std::cout << BOLD << "\n----SET IDEA FOR DOG----\n" << COLOR_DEFAULT;
	Dog pollux;
	pollux.setIdea("I want your food! WAF WAF WAF!", 0);
	std::cout << pollux.getIdea(0) << std::endl;

	std::cout << BOLD << "\n----SET IDEA FOR DOG WITH WRONG INDEXING----\n" << COLOR_DEFAULT;
	try
	{
		pollux.setIdea("I want your food! WAF WAF WAF!", -1);
	}
	catch(const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
	std::cout << pollux.getIdea(-1) << std::endl;
	}
	catch(const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	
	std::cout << BOLD << "\n----SET IDEA FOR CAT----\n" << COLOR_DEFAULT;
	Cat sardine;
	sardine.setIdea("I want your food! MEOW MEOW MEOW!", 0);
	std::cout << sardine.getIdea(0) << std::endl;
	
	std::cout << BOLD << "\n----COPY CONSTRUCTOR TESTS ON DOG----\n" << COLOR_DEFAULT;
	Dog havana(pollux);
	std::cout << "Copy constructor: Before idea changed: " << havana.getIdea(0) << std::endl;
	havana.setIdea("I want cuddles! WAF WAF WAF!", 0);
	std::cout << "Copy consturctor: After idea changed: " << havana.getIdea(0) << std::endl;

	std::cout << BOLD << "\n----COPY CONSTRUCTOR TESTS ON CAT----\n" << COLOR_DEFAULT;
	Cat salmon(sardine);
	std::cout << "Copy constructor: Before idea changed: " << salmon.getIdea(0) << std::endl;
	salmon.setIdea("I want cuddles! MEOW MEOW MEOW!", 0);
	std::cout << "Copy consturctor: After idea changed: " << salmon.getIdea(0) << std::endl;

	// SET SECOND IDEA INTO DOG'S BRAIN	
	havana.setIdea("I want to cuddle with my human! WAF WAF WAF!", 1);

	// SET SECOND IDEA INTO CAT'S BRAIN	
	salmon.setIdea("I want to cuddle with my human! MEOW MEOW MEOW!", 1);	
	
	std::cout << BOLD << "\n----ASSIGNMENT OPERATOR TESTS ON DOG----\n" << COLOR_DEFAULT;
	std::cout << "Before assignment: " << pollux.getIdea(1) << std::endl;
	pollux = havana;
	std::cout << "After assignment: " << pollux.getIdea(1) << std::endl;
	
	std::cout << BOLD << "\n----ASSIGNMENT OPERATOR TESTS ON CAT----\n" << COLOR_DEFAULT;
	std::cout << "Before assignment: " << sardine.getIdea(1) << std::endl;
	sardine = salmon;
	std::cout << "After assignment: "<< sardine.getIdea(1) << std::endl;

	std::cout << BOLD << "\n----DESTRUCTOR TESTS ON ARRAY OF DOGS AND CATS----\n" << COLOR_DEFAULT;
	for (int i = 0; i < count; i++)
		delete animal[i];

	std::cout << BOLD << "\n----DESTRUCTOR TESTS ON COPY CREATED OBJECTS EARLIER----\n" << COLOR_DEFAULT;
return 0;
}