/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:17:47 by jchartie          #+#    #+#             */
/*   Updated: 2026/08/04 18:31:13 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) 
{
	Point a(1, 1);
	Point b(3, 9);
	Point c(5, 4);
	Point point(3, 4);

	if (bsp(a, b, c, point))
		std::cout << "point is in triangle\n";
	else
		std::cout << "point is outside triangle\n";
	return 0;
}