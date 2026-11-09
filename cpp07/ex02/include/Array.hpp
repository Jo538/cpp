/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/09 12:04:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "color.h"

enum Action
{
	DEFAULT_CONSTRUCTOR,
	SPEC_CONSTRUCTOR,
	COPY_CONSTRUCTOR,
	COPY_ASSIGN_OPERATOR,
	DESTRUCTOR
};

template <typename T>
class Array
{
private:
	T* arr;
	size_t size;
	static const char* color;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();
	
	static void printMessage(Action item);
};

template<typename T>
const char* Array<T>::color = COLOR_DEFAULT;

template<>
const char* Array<int>::color = COLOR_CYAN;

template<>
const char* Array<std::string>::color = COLOR_MAGENTA;

template <typename T>
Array<T>::Array() : arr(NULL), size(0)
{
	printMessage(DEFAULT_CONSTRUCTOR);
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), size(n)
{
	printMessage(SPEC_CONSTRUCTOR);
}

template <typename T>
Array<T>::Array(const Array& other)
{
	printMessage(COPY_CONSTRUCTOR);
	this->arr = new T[other.size];
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	printMessage(COPY_ASSIGN_OPERATOR);

	delete[] this->arr;
	this->arr = new T[other.size];
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	printMessage(DESTRUCTOR);
	delete[] arr;
}

template<typename T>
void Array<T>::printMessage(Action item)
{
	std::cout << Array<T>::color << "[Array<>] " << COLOR_DEFAULT;
	switch(item)
	{
		case DEFAULT_CONSTRUCTOR:
		{
			std::cout << "Default constructor called" << std::endl;
			break ;
		}
		case SPEC_CONSTRUCTOR:
		{
			std::cout << "Spec constructor called" << std::endl;
			break ;
		}
		case COPY_CONSTRUCTOR:
		{
			std::cout << "Copy constructor called" << std::endl;
			break ;
		}
		case COPY_ASSIGN_OPERATOR:
		{
			std::cout << "Copy assignment operator called" << std::endl;
			break ;
		}
		case DESTRUCTOR:
		{
			std::cout << "Destructor called" << std::endl;
			break ;
		}
	}
}

#endif
