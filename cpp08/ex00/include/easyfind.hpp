/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:27:56 by admin             #+#    #+#             */
/*   Updated: 2026/11/11 16:46:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class IntNotFound : public std::exception
{
public:
	const char* what() const throw() { return "Value not found";}	
};

template <typename T>
void easyfind(const T& container, const int num)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), num);

	if (it == container.end())
		throw IntNotFound();
	else
		std::cout << "Value " <<  num << " found" << std::endl;
}

#endif