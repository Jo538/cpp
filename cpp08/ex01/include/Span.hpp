/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:00:28 by admin             #+#    #+#             */
/*   Updated: 2026/11/12 19:24:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>

class Span
{
private:
	static unsigned int DEFAULT_MAX;
	unsigned int max;
	std::multiset<int> set;

public:
	Span();
	Span(unsigned int num);
	Span(const Span& other);
	~Span();

	unsigned int getMax() const;
	size_t getSetSize() const;
	const std::multiset<int>& getSet() const;

	void addNumber(int num);
	template <typename T>
	void addRange(T begin, T end) { this->set.insert(begin, end); };
	int longestSpan();
	int shortestSpan();

	Span& operator=(const Span& other);
};

std::ostream& operator<<(std::ostream& os, const Span& object);

#endif