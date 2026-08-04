/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:17:47 by jchartie          #+#    #+#             */
/*   Updated: 2026/08/04 20:33:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) 
{
	Point triangle[4][3] = {{Point(1, 2), Point(1, 2), Point(1, 2)},
						   {Point(4, 9), Point(4, 9), Point(5, 4)},
						   {Point(5, 4), Point(5, 4), Point(4, 9)},
						   {Point(3, 4), Point(10, 10), Point(3, 4)}};

	std::string test[3] = {"Test 1: a(1, 2), b(4, 9), c(5, 4), p(3, 4)\n",
						   "\nTest 2: a(1, 2), b(4, 9), c(5, 4), p(10, 10)\n",
						   "\nTest 3: a(1, 2), b(5, 4), c(4, 9), p(3, 4)\n"};
	for (int i=0; i < 3; i++)
	{
		std::cout << test[i];
		if (bsp(triangle[0][i], triangle[1][i], triangle[2][i], triangle[3][i]))
			std::cout << "point is in triangle\n";
		else
			std::cout << "point is outside triangle\n";		
	}

	return 0;
}
