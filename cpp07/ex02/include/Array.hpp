/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:14 by admin             #+#    #+#             */
/*   Updated: 2026/11/09 15:33:40 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <typeinfo>
# include <exception>
# include "color.h"

/* ************************************************************************** */
/*   Logging actions (used by printMessage / recogniseAction)                 */
/* ************************************************************************** */

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
	size_t _size;
	static const char* color;

	static void printMessage(Action item);
	static std::string recogniseType();
	static std::string recogniseAction(Action item);

public:
	// Orthodox Canonical Form
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	// Element access
	T& operator[](const int index);
	T& getElement(size_t index);
	size_t size() const;

	// Whole-array helpers
	void setArr(T item);
	std::string getArr() const;

	class BadSubscript;
};

/* ************************************************************************** */
/*   Exception                                                                */
/* ************************************************************************** */

template <typename T>
class Array<T>::BadSubscript : public std::exception
{
public:
	const char *what() const throw();
};

template <typename T>
const char *Array<T>::BadSubscript::what() const throw()
{
	return "Error: Index out of bounds.";
}

/* ************************************************************************** */
/*   Colour per type (static member + specializations)                        */
/* ************************************************************************** */

template <typename T>
const char* Array<T>::color = COLOR_DEFAULT;

template <>
const char* Array<int>::color = COLOR_CYAN;

template <>
const char* Array<std::string>::color = COLOR_MAGENTA;

/* ************************************************************************** */
/*   Orthodox Canonical Form                                                  */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : arr(NULL), _size(0)
{
	printMessage(DEFAULT_CONSTRUCTOR);
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), _size(n)
{
	printMessage(SPEC_CONSTRUCTOR);
}

template <typename T>
Array<T>::Array(const Array& other)
{
	printMessage(COPY_CONSTRUCTOR);
	this->arr = new T[other._size]();
	this->_size = other._size;
	for (size_t i = 0; i < _size; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	printMessage(COPY_ASSIGN_OPERATOR);

	if (this == &other)
		return *this;

	delete[] this->arr;
	this->_size = other._size;
	this->arr = new T[other._size]();
	for (size_t i = 0; i < _size; i++)
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

/* ************************************************************************** */
/*   Element access                                                           */
/* ************************************************************************** */

template <typename T>
T& Array<T>::operator[](const int index)
{
	return this->getElement(index);
}

template <typename T>
T& Array<T>::getElement(size_t index)
{
	if (index < 0 || index >= _size)
		throw BadSubscript();
	return this->arr[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return this->_size;
}

/* ************************************************************************** */
/*   Whole-array helpers                                                      */
/* ************************************************************************** */

template <typename T>
void Array<T>::setArr(T item)
{
	for (size_t i = 0; i < _size; i++)
	{
		this->arr[i] = item;
	}
}

template <typename T>
std::string Array<T>::getArr() const
{
	std::ostringstream out;

	for (size_t i = 0; i < _size; i++)
	{
		out << this->arr[i] << " ";
	}

	return out.str();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T>& other)
{
	return os << other.getArr();
}

/* ************************************************************************** */
/*   Private logging helpers                                                  */
/* ************************************************************************** */

template <typename T>
void Array<T>::printMessage(Action item)
{
	std::cout << Array<T>::color << "[Array<";
	std::cout << recogniseType();
	std::cout << ">] " << COLOR_DEFAULT;
	std::cout << recogniseAction(item);
}

template <typename T>
std::string Array<T>::recogniseType()
{
	std::ostringstream out;

	if (typeid(T) == typeid(int))
		out << "int";
	if (typeid(T) == typeid(std::string))
		out << "string";
	return out.str();
}

template <typename T>
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

#endif
