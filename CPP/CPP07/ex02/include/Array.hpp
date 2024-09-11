/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:33:20 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/09 17:05:23 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <sstream>
# include <exception>

template <typename T>
class Array
{
	private:
		T	*_arr;
		int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &source);
		~Array(void);

		Array &operator = (Array const &src);

		T &operator [](int i);
		unsigned int	size(void) const;
};

template <typename T>
Array<T>::Array(void) : _arr(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &source) : _arr(new T[source.size]), _size(source.size)
{
	for (int i = 0; i < source._size; i++)
		_arr[i] = source._arr[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _arr;
}

template <typename T>
Array<T> &	Array<T>::operator=(Array const &src)
{
	if (this != &src)
	{
		delete [] _arr;
		_size = src.size();
		_arr = new T[_size];
		for (int i = 0; i < _size; i++)
			_arr[i] = src._arr[i];
	}
	return (*this);
}

template <typename T>
T &	Array<T>::operator[](int i)
{
	if (i < 0 || i >= _size)
		throw std::exception();
	return (this->_arr[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
    return (_size);
}

