/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:44:25 by admin             #+#    #+#             */
/*   Updated: 2026/11/11 17:12:43 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"
#include "color.h"

enum ContainerType
{
	VECTOR,
	DEQUE,
	LIST
};

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

// "▸ what is being tested"
template <typename T>
static void	test(int num, const ContainerType type, const T& container)
{
	std::cout << "\n" << BOLD << "▸ Find " << num
	<< " in ";

	switch (type)
	{
		case VECTOR:
			std::cout << "vector";
		case DEQUE:
			std::cout << "double-ended queue";
		case LIST:
			std::cout << "list";
	}
	std::cout << " [";
	
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it;
		if (&*it != &container.back())
			std::cout << " ";
	}
	std::cout << "]" << COLOR_DEFAULT << std::endl;
}

static void testOutcome(bool result, bool expected)
{
	std::cout << (result == expected ? COLOR_GREEN "✔ PASS" : COLOR_RED "✘ FAIL")
		<< COLOR_DEFAULT << std::endl;
}

template <typename T>
static bool callEasyFind(const T& container, int num)
{
	try
	{
		easyfind(container, num);
		return true;
	}
	catch(const IntNotFound& e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
}

template <typename T>
static void launchTestSuite(const int num, const T& container, ContainerType type, bool expected)
{
	bool found = false;
	
	test(num, type, container);
	found = callEasyFind(container, num);
	testOutcome(found, expected);	
}

int main(void)
{
	int raw[4] = {1, 2, 3, 4};

	section(1, "Vector of ints");
	std::vector<int> vec(raw, raw + 4);
	
	launchTestSuite(2, vec, VECTOR, true);
	launchTestSuite(5, vec, VECTOR, false);

	section(2, "Double-ended queue of ints");
	std::deque<int> deq(raw, raw + 4);

	launchTestSuite(2, deq, DEQUE, true);
	launchTestSuite(5, deq, DEQUE, false);

	section(3, "List of ints");
	std::list<int> lst(raw, raw + 4);

	launchTestSuite(2, lst, LIST, true);
	launchTestSuite(5, lst, LIST, false);
}