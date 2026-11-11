/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:00:28 by admin             #+#    #+#             */
/*   Updated: 2026/11/11 18:50:56 by admin            ###   ########.fr       */
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
	Span& operator=(const Span& other);
	~Span();
};

#endif