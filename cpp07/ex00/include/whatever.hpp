/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/08 13:43:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y)
{
	T tmp = x;

	x = y;
	y = tmp;
}

template <typename T>
const T& min(const T& v1, const T& v2)
{
	return (v1 < v2 ? v1 : v2);
}

template <typename T>
const T& max(const T& v1, const T& v2)
{
	return (v1 > v2 ? v1 : v2);
}

#endif
