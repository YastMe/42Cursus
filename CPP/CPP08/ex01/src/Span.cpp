/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:22:32 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 13:39:59 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(void): _N(0), _size(0) { return ; }
Span::Span(unsigned int n): _N(n), _size(0) { return ; }
Span::Span(Span const &src) { *this = src; }
Span::~Span(void) { return ; }

Span & Span::operator = (const Span &span)
{
	if (this != &span)
	{
		_N = span._N;
		_size = span._size;
		_list = span._list;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Span &span)
{

	std::list<int>	aux = span.getList();
	for (std::list<int>::iterator it = aux.begin(); it != aux.end(); it++)
		out << *it << " ";
	return (out);
}

static void correctLength(Span &span)
{
	if (span.getSize() > span.getN())
		throw std::length_error("Exceeded the maximum length for the list.");
	else if (span.getSize() <= 1)
		throw std::length_error("The list must have at least two elements to calculate the span.");
}

void	Span::addNumber(int n)
{
	if (_size < _N)
	{	
		_list.push_back(n);
		_size++;
	}
	else
		std::cerr << "Exceeded the maximum length for the list." << std::endl;
}

int	Span::shortestSpan(void)
{
	std::list<int>	aux = _list;
	std::list<int>	diff;

	try
	{
		correctLength(*this);
		aux.sort();
		std::adjacent_difference(aux.begin(), aux.end(), std::back_inserter(diff));
		return (*std::min_element(diff.begin(), diff.end()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		return (-1);
	}	
}

int	Span::longestSpan(void)
{
	std::list<int>	aux = _list;

	try
	{
		correctLength(*this);
		aux.sort();
		return (std::abs(aux.back() - aux.front()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		return (-1);
	}
}

int	Span::getSize(void) const { return (_size); }
int	Span::getN(void) const { return (_N); }
std::list<int> Span::getList(void) const { return (_list); }

void	Span::randomFill(void)
{
	for (unsigned int i = _size; i < _N; i++)
		_list.push_back(rand() % 1000);
	_size = _N;
}
