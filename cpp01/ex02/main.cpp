/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:17:16 by jchartie          #+#    #+#             */
/*   Updated: 2026/07/28 16:28:18 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "Print memory addresses --> \n"
	          << "string: " << &string << std::endl
			  << "stringPTR: " << stringPTR << std::endl
			  << "stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Print values --> \n"
	          << "string: " << string << std::endl
			  << "stringPTR: " << *stringPTR << std::endl
			  << "stringREF: " << stringREF << std::endl << std::endl;
}