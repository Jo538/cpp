/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:07:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/16 14:45:46 by admin            ###   ########.fr       */
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

static void	test(const std::string& what)
{
	std::cout << "\n" << BOLD << "▸ " << what << COLOR_DEFAULT << std::endl;
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
	test("Iterate through MutantStack<int> a  = [42, 51, 99]");
	a.printContainer();	

	b.populateFromArr(arr_str, 3);
	test("Iterate through MutantStack<std::string> b  = [\"Havana\", \"and\", \"Pollux\"]");
	b.printContainer();

	section(3, "Call copy constructor, MutantStack");
	test("Copy a = [42, 51, 99]");
	MutantStack<int> g(a);
	std::cout << "New MutantStack: ";
	g.printContainer();
	printTestOutcome(compareContainers(a, g));

	section(4, "Call copy assignment operator, MutantStack");
	MutantStack<std::string> h;
	std::cout << "MutantStack before copy: " << (h.empty() ? "empty\n" : "not empty\n");
	h = b;
	std::cout << "MutantStack after copy: ";
	h.printContainer();
	printTestOutcome(compareContainers(b, h));	

	section(5, "Compare MutantStack with vs std::vector");
	std::vector<int> c(arr_int, arr_int + 3);
	std::vector<std::string> d(arr_str, arr_str + 3);

	test("std::vector<int>c & MutantStack<int>a = [42, 51, 99]");
	printTestOutcome(compareContainers(a, c));

	test("std::vector<std::string>d & MutantStack<std::string>b = [\"Havana\", \"and\", \"Pollux\"]");
	printTestOutcome(compareContainers(b, d));

	section(6, "Compare MutantStack with vs std::list");
	std::list<int> e(arr_int, arr_int + 3);
	std::list<std::string> f(arr_str, arr_str + 3);

	test("std::list<int>e & MutantStack<int>a = [42, 51, 99]");
	printTestOutcome(compareContainers(a, e));

	test("std::list<std::string>f & MutantStack<std::string>b = [\"Havana\", \"and\", \"Pollux\"]");
	printTestOutcome(compareContainers(b, f));
	
	section(7, "Call destructors");
}