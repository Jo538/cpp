/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/08 17:48:20 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T* arr;
	size_t size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();	
};

template <typename T>
Array<T>::Array() : arr(NULL), size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), size(n)
{
	std::cout << "Spec constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->arr = new T[other.size];
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

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
	std::cout << "Destructor called" << std::endl;
	delete[] arr;
}

#endif
