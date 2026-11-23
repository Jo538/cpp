/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/23 11:42:04 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void printValue(T& var)
{
	std::cout << var << std::endl;
}

template <typename C, typename T>
void iter(C* address, int length, void (*func)(T&))
{
	for (int i = 0; i < length; i++)
	{
		func(address[i]);
	}
}

#endif
