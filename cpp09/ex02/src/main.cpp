/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:54:28 by admin             #+#    #+#             */
/*   Updated: 2026/11/26 13:52:25 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PMergeMe.hpp"

// 4 2 3
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}
	
	std::vector<std::string> numbers;
	for (int i = 1; i < argc; ++i)
		numbers.push_back(argv[i]);
	
	PMergeMe test(numbers);
	
	return 0;
}