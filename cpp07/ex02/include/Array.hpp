/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/09 13:39:50 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <typeinfo>
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
	
	static void printMessage(Action item);
	static std::string recogniseType();
	static std::string recogniseAction(Action item);
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	T& operator[](const int index);
	~Array();

	void setArr(T item);
	std::string getArr() const;
	T& getElement(const int index);
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Array<T>& other)
{
	return os << other.getArr();
}

template<typename T>
T& Array<T>::getElement(const int index)
{
	return this->arr[index];
}

template<typename T>
T& Array<T>::operator[](const int index)
{
	return this->getElement(index);
}

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
	this->size = other.size;
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
	this->size = other.size;
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
std::string Array<T>::recogniseType()
{
	std::ostringstream out;
	
	if (typeid(T) == typeid(int))
		out << "int";
	if (typeid(T) == typeid(std::string))
		out << "string";
	return out.str();
}

template<typename T>
std::string Array<T>::recogniseAction(Action item)
{
	std::ostringstream out;

	switch(item)
	{
		case DEFAULT_CONSTRUCTOR:
		{
			out << "Default constructor called" << std::endl;
			break ;
		}
		case SPEC_CONSTRUCTOR:
		{
			out << "Spec constructor called" << std::endl;
			break ;
		}
		case COPY_CONSTRUCTOR:
		{
			out << "Copy constructor called" << std::endl;
			break ;
		}
		case COPY_ASSIGN_OPERATOR:
		{
			out << "Copy assignment operator called" << std::endl;
			break ;
		}
		case DESTRUCTOR:
			out << "Destructor called" << std::endl;
	}
	return out.str();
}

template<typename T>
void Array<T>::printMessage(Action item)
{
	std::cout << Array<T>::color << "[Array<";
	std::cout << recogniseType();
	std::cout << ">] " << COLOR_DEFAULT;
	std::cout << recogniseAction(item);
}

template<typename T>
void Array<T>::setArr(T item)
{
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = item;
	}
}

template<typename T>
std::string Array<T>::getArr() const
{
	std::ostringstream out;

	for (size_t i = 0; i < size; i++)
	{
		out << this->arr[i] << " ";
	}
	
	return out.str();
}

#endif
