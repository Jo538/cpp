/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:50:29 by admin             #+#    #+#             */
/*   Updated: 2026/11/27 17:00:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PMergeMe.hpp"

PMergeMe::PMergeMe(const std::vector<std::string>& numbers)
{
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		std::istringstream iss(numbers[i]);
		int n;

		iss >> n;
		_numbers.push_back(n);
	}
}

const PMergeMe::Suite& PMergeMe::getNumbers() const
{
	return _numbers;
}

PMergeMe::Suite PMergeMe::mySort() const
{
	return mergeInsert(_numbers);
}

PMergeMe::Suite PMergeMe::mergeInsert(const Suite& nums)
{
	if (nums.size() < 2)
		return nums;

	// Steps 1-2: pair up, bigger number first in each pair
	Pairs pairs = makePairs(nums);

	// Step 3: sort the winners with this same algorithm
	Suite chain = mergeInsert(winnersOf(pairs));

	// Step 4: pending losers, in the same order as their winners in the chain
	Pairs pending = orderByChain(pairs, chain);

	// Step 5: the loser of the smallest winner goes in front for free
	chain.insert(chain.begin(), pending[0].second);
	pending.erase(pending.begin());

	return chain;
}

PMergeMe::Pairs PMergeMe::makePairs(const Suite& nums)
{
	Pairs pairs;

	for (size_t i = 0; i + 1 < nums.size(); i += 2)
	{
		if (nums[i] > nums[i + 1])
			pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
		else
			pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
	}
	return pairs;
}

PMergeMe::Suite PMergeMe::winnersOf(const Pairs& pairs)
{
	Suite winners;

	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);
	return winners;
}

PMergeMe::Pairs PMergeMe::orderByChain(Pairs pairs, const Suite& chain)
{
	Pairs ordered;

	for (size_t c = 0; c < chain.size(); ++c)
	{
		for (size_t p = 0; p < pairs.size(); ++p)
		{
			if (pairs[p].first == chain[c])
			{
				ordered.push_back(pairs[p]);
				pairs.erase(pairs.begin() + p);
				break;
			}
		}
	}
	return ordered;
}
