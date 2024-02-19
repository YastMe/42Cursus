/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:40 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 16:11:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal()
{
	_type = "Generic animal";
	std::cout << "Default constructor called on " << *this << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "Type constructor called on " << *this << std::endl;
}

Animal::Animal(const Animal &animal)
{
	_type = animal._type;
	std::cout << "Copy constructor called on " << *this << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called on " << *this << std::endl;
}

Animal & Animal::operator = (const Animal &animal)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	if (&animal != this)
	{
		_type = animal._type;
	}
	return (*this);
}

std::string Animal::getType(void) const
{
	return (_type);
}

void	Animal::setType(std::string type)
{
	_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << " · · · " << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Animal &animal)
{
	out << "Animal [" << animal.getType() << "]";
	return (out);
}