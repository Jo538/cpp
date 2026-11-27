/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:47:10 by admin             #+#    #+#             */
/*   Updated: 2026/11/27 13:18:52 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <string>
# include <vector>

class PMergeMe
{
public:
	PMergeMe() {};
	PMergeMe(const std::vector<std::string>& numbers);
	PMergeMe(const PMergeMe& other) : _numbers(other._numbers) {};
	PMergeMe& operator=(const PMergeMe& other) {_numbers = other._numbers; return *this;};
	~PMergeMe() {};

	typedef std::vector<unsigned int> Suite;
	
	const Suite& getNumbers();

private:
	Suite _numbers;

};

#endif