/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:12:57 by admin             #+#    #+#             */
/*   Updated: 2026/11/16 14:34:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "MutantStack.hpp"
#include <color.h>

template<typename T>
const char* MutantStack<T>::color = COLOR_DEFAULT;

template<>
const char* MutantStack<int>::color = COLOR_BLUE;

template<>
const char* MutantStack<std::string>::color = COLOR_MAGENTA;

template <typename T>
MutantStack<T>::MutantStack()
{
	printMessage("Default constructor called");
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other)
{
	printMessage("Copy constructor called");
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	printMessage("Copy assignment operator called");
	std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	printMessage("Destructor called");
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
void MutantStack<T>::printMessage(std::string message) const
{
	std::cout << this->color << "[MutantStack<";
	if (typeid(T) == typeid(int))
		std::cout << "int>] ";
	if (typeid(T) == typeid(std::string))
		std::cout << "std::string>] ";
	std::cout << COLOR_DEFAULT << message << std::endl;
}

template <typename T>
void MutantStack<T>::populateFromArr(T* arr, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		this->push(arr[i]);
	// this->c.insert(this->begin(), arr, arr + length); improved version
}

template <typename T>
void MutantStack<T>::printContainer() const
{
	const_iterator it = this->begin();
	const_iterator ite = this->end();

	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
