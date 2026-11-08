/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/08 14:08:23 by admin            ###   ########.fr       */
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

template <typename T>
void iter(T* address, int length, void (*func)(T&))
{
	for (int i = 0; i < length; i++)
	{
		func(address[i]);
	}
}

#endif
