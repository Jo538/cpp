/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:59:40 by admin             #+#    #+#             */
/*   Updated: 2026/11/13 15:56:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <deque>
# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	static const char* color;
	
public:

	MutantStack();
	MutantStack(const MutantStack<T>& other);
	MutantStack<T>& operator=(const MutantStack<T>& other);
	~MutantStack();
	
	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename std::deque<T>::const_iterator const_iterator;
	const_iterator begin() const;
	const_iterator end() const;
};



# include "MutantStack.tpp"

#endif