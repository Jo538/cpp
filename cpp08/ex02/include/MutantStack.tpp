/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:12:57 by admin             #+#    #+#             */
/*   Updated: 2026/11/13 16:00:47 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <color.h>

template<typename T>
const char* MutantStack<T>::color = COLOR_DEFAULT;

template<>
const char* MutantStack<int>::color = COLOR_BLUE;

template<>
const char* MutantStack<int>::color = COLOR_MAGENTA;

template<>
const char* MutantStack<int>::color = COLOR_YELLOW;

template <typename T>
MutantStack<T>::MutantStack()
{
	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>&)
{
	
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>&)
{
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& container)
{
	return os << container.top();
}