/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:43 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 16:23:43 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Default constructor called on " << *this << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	*this = cat;
	std::cout << "Copy constructor called on " << *this << std::endl;
}

Cat::Cat(Brain &brain): Animal("Cat")
{
	std::cout << "Brain constructor called on " << *this << std::endl;
	_brain = &brain;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Destructor called on " << *this << std::endl;
}

Cat & Cat::operator = (const Cat &cat)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	if (&cat != this)
	{
		_type = cat._type;
		_brain = cat._brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Cat &cat)
{
	out << "Cat [" << cat.getType() << "]";
	return (out);
}