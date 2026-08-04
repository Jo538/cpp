/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:17:47 by jchartie          #+#    #+#             */
/*   Updated: 2026/08/04 21:26:37 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Point.hpp"

int main( void ) 
{
	Point triangle[3][4] = {{Point(1, 2), Point(4, 9), Point(5, 4), Point(3, 4)},
						   {Point(1, 2), Point(4, 9), Point(5, 4), Point(10, 10)},
						   {Point(1, 2), Point(5, 4), Point(4, 9), Point(3, 4)}};

	for (int i=0; i < 3; i++)
	{
		std::cout << "a" << triangle[i][0]
				  << "b" << triangle[i][1]
				  << "c" << triangle[i][2]
				  << "p" << triangle[i][3] << std::endl;
		if (bsp(triangle[i][0], triangle[i][1], triangle[i][2], triangle[i][3]))
			std::cout << "point is in triangle\n\n";
		else
			std::cout << "point is outside triangle\n\n";				
	}

	return 0;
}
