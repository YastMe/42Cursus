/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:47:36 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 13:49:43 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &src);
		~MutantStack(void);
		MutantStack & operator = (const MutantStack &stack);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);
};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() { return ; }

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) { *this = src; }

template <typename T>
MutantStack<T>::~MutantStack(void) { return ; }

template <typename T>
MutantStack<T> & MutantStack<T>::operator = (const MutantStack &stack)
{
	if (this != &stack)
		std::stack<T>::operator=(stack);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}
