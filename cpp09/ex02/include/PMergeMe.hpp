/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:47:10 by admin             #+#    #+#             */
/*   Updated: 2026/11/27 17:00:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <string>
# include <utility>
# include <vector>

class PMergeMe
{
public:
	typedef std::vector<unsigned int> Suite;

	PMergeMe() {}
	PMergeMe(const std::vector<std::string>& numbers);
	PMergeMe(const PMergeMe& other) : _numbers(other._numbers) {}
	PMergeMe& operator=(const PMergeMe& other) { _numbers = other._numbers; return *this; }
	~PMergeMe() {}

	const Suite& getNumbers() const;
	Suite mySort() const;

private:
	// first = winner (bigger), second = loser (smaller)
	typedef std::pair<unsigned int, unsigned int> Pair;
	typedef std::vector<Pair> Pairs;

	Suite _numbers;

	static Suite mergeInsert(const Suite& nums);
	static Pairs makePairs(const Suite& nums);
	static Suite winnersOf(const Pairs& pairs);
	static Pairs orderByChain(Pairs pairs, const Suite& chain);
};

#endif
