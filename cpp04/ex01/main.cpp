/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:46:31 by admin             #+#    #+#             */
/*   Updated: 2026/08/10 13:09:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "color.h"

int main(void)
{
	std::cout << BOLD << "----DEFAULT CONSTRUCTOR TESTS FOR AN ARRAY OF CATS & DOGS----\n" << COLOR_DEFAULT;
	Animal *animal[Animal::ANIMAL_COUNT];
	
	for (int i = 0; i < (Animal::ANIMAL_COUNT / 2); i++)
		animal[i] = new Dog();
	for (int i = (Animal::ANIMAL_COUNT / 2); i < Animal::ANIMAL_COUNT; i++)
		animal[i] = new Cat();

	std::cout << BOLD << "\n----COPY CONSTRUCTOR TESTS ON DOG----\n" << COLOR_DEFAULT;
	Dog pollux;
	Dog havana(pollux);

	std::cout << BOLD << "\n----COPY CONSTRUCTOR TESTS ON CAT----\n" << COLOR_DEFAULT;
	Cat sardine;
	Cat salmon(sardine);

	std::cout << BOLD << "\n----ASSIGNMENT OPERATOR TESTS ON DOG----\n" << COLOR_DEFAULT;
	pollux = havana;

	std::cout << BOLD << "\n----ASSIGNMENT OPERATOR TESTS ON CAT----\n" << COLOR_DEFAULT;
	sardine = salmon;

	std::cout << BOLD << "\n----DESTRUCTOR TESTS ON ARRAY OF DOGS AND CATS----\n" << COLOR_DEFAULT;
	for (int i = 0; i < Animal::ANIMAL_COUNT; i++)
		delete animal[i];

	std::cout << BOLD << "\n----DESTRUCTOR TESTS ON COPY CREATED OBJECTS EARLIER----\n" << COLOR_DEFAULT;
return 0;
}