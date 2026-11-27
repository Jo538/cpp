/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:50:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/27 13:19:53 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "PMergeMe.hpp"

PMergeMe::PMergeMe(const std::vector<std::string>& numbers)
{
	std::vector<std::string>::const_iterator it = numbers.begin();
	
	for (; it != numbers.end(); ++it)
	{
		std::istringstream iss(*it);
		int n;

		iss >> n;
		_numbers.push_back(n);
	}
	
}

const PMergeMe::Suite& PMergeMe::getNumbers()
{
	return _numbers;
}