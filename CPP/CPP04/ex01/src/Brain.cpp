/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:37:19 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 15:37:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called on " << *this << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Copy constructor called on " << *this << std::endl;
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "Destructor called on " << *this << std::endl;
}

Brain & Brain::operator = (const Brain &brain)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return (*this);
}

bool	Brain::addIdea(std::string idea)
{
	if (idea == "")
		return (false);
	for (int i = 0; i < 100; i++)
	{
		if (_ideas[i] == "")
		{
			_ideas[i] = idea;
			return (true);
		}
	}
	return (false);
}

std::string	Brain::getIdea(int i)
{
	if (i >= 100)
		return (NULL);
	return (_ideas[i]);
}

std::ostream &operator<<(std::ostream &out, const Brain &brain)
{
	out << "Brain [" << &brain << "]";
	return (out);
}