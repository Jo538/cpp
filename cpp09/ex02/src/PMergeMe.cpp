/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:50:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/27 14:11:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <utility>
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

const PMergeMe::Pairs PMergeMe::pairNums() const
{
	Pairs pairNums;

	for (size_t i = 0; (i + 1) < _numbers.size(); i += 2)
		pairNums.push_back(std::make_pair(_numbers[i], _numbers[i + 1]));

	return pairNums;
}

const PMergeMe::Suite PMergeMe::findWinners(const Pairs& pairNums)
{
	Suite winners;

	for (size_t i = 0; i < pairNums.size(); ++i)
	{
		if (pairNums[i].first > pairNums[i].second)
			winners.push_back(pairNums[i].first);
		else
			winners.push_back(pairNums[i].second);
	}
	return winners;
}

const PMergeMe::Suite PMergeMe::mySort()
{
	const Pairs pairs = pairNums();
	const Suite winners = findWinners(pairs);
	const Suite rankedWinners = rankWinners(winners);
	
	return rankedWinners;
}

const PMergeMe::Suite PMergeMe::rankWinners(const Suite& winners)
{
	Suite rankedWinners;

	if (winners[0] > winners[1])
	{
		rankedWinners.push_back(winners[1]);
		rankedWinners.push_back(winners[0]);
	}
	else
	{
		rankedWinners.push_back(winners[0]);
		rankedWinners.push_back(winners[1]);		
	}
	return rankedWinners;
}