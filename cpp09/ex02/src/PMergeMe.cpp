/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:50:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/26 14:00:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PMergeMe.hpp"

// go from "4 7 9 5" to [4, 7, 9, 5]
PMergeMe::PMergeMe(const std::vector<std::string>& numbers)
{
	std::vector<std::string>::const_iterator it = numbers.begin();
	for (; it != numbers.end(); ++it)
	{
		std::istringstream iss(*it);
		unsigned int n;

		iss >> n;
		_numbers.push_back(n);
	}
}