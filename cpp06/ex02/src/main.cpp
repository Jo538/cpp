/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:42:42 by admin             #+#    #+#             */
/*   Updated: 2026/11/04 22:02:21 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.h"

static void	section(int number, const std::string& title)
{
	const std::string	line = "══════════════════════════════════════════════";

	std::cout << "\n" << BOLD << line << "\n " << number << ". " << title
		<< "\n" << line << COLOR_DEFAULT << std::endl;
}

Base* generate(void)
{
	std::srand(time(NULL));
	
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object type: A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Object type: B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Object type: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Object type: A" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Object type: B" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Object type: C" << std::endl;
		return ;
	}
	catch(const std::bad_cast& e) {}
}

int main(void)
{
	section(1, "Create Random Object: A, B, or C");
	Base* ptr = generate();
	Base& ref = *ptr;
	
	section(2, "Identify Dynamic Object Type Using Pointer");
	identify(ptr);

	section(3, "Identify Dynamic Object Type Using Ref");
	identify(ref);

	section(4, "Delete Object");
	delete ptr;
}
