/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:07:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/16 11:50:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

template <typename T, typename C>
bool compareContainers(const MutantStack<T>& stack, C& container)
{
	typename MutantStack<T>::const_iterator it_stack = stack.begin();
	typename MutantStack<T>::const_iterator ite_stack = stack.end();

	typename C::const_iterator it_container = container.begin();
	typename C::const_iterator ite_container = container.end();

	for (; (it_container != ite_container) && (it_stack != ite_stack); ++it_container, ++it_stack)
	{
		if (*it_stack != *it_container)
			return false;
	}
	return true;
}

static void printTestOutcome(bool outcome)
{
		std::cout << (outcome == true ? COLOR_GREEN "✔ PASS" : COLOR_RED "✘ FAIL")
		<< COLOR_DEFAULT << std::endl;
	
}

int main(void)
{
	section(1, "Call default constructor, MutantStack");
	
	MutantStack<int> a;
	MutantStack<std::string> b;

	section(2, "Populate stack & retrieve content");
	int arr_int[] = {42, 51, 99};
	std::string arr_str[] = {"Havana", "and", "Pollux"};
	
	a.populateFromArr(arr_int, 3);
	a.printContainer();	

	b.populateFromArr(arr_str, 3);
	b.printContainer();

	section(3, "Compare MutantStack with vs std::vector");
	std::vector<int> c(arr_int, arr_int + 3);
	std::vector<std::string> d(arr_str, arr_str + 3);

	printTestOutcome(compareContainers(a, c));
	printTestOutcome(compareContainers(b, d));

	section(4, "Compare MutantStack with vs std::list");
	std::list<int> e(arr_int, arr_int + 3);
	std::list<std::string> f(arr_str, arr_str + 3);

	printTestOutcome(compareContainers(a, e));
	printTestOutcome(compareContainers(b, f));
	
	section(5, "Call destructors");
}