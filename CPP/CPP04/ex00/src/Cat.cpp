/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:43 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:01:35 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Default constructor called on " << *this << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	std::cout << "Copy constructor called on " << *this << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called on " << *this << std::endl;
}

Cat & Cat::operator = (const Cat &cat)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	if (&cat != this)
		_type = cat._type;
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