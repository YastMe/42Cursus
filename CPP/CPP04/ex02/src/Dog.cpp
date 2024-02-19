/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:41:46 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 16:19:49 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Default constructor called on " << *this << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	*this = dog;
	std::cout << "Copy constructor called on " << *this << std::endl;
}

Dog::Dog(Brain &brain): Animal("Dog")
{
	std::cout << "Brain constructor called on " << *this << std::endl;
	_brain = &brain;
}

Dog::~Dog()
{
	std::cout << "Destructor called on " << *this << std::endl;
}

Dog & Dog::operator = (const Dog &dog)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	if (&dog != this)
	{
		_type = dog._type;
		_brain = dog._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Dog &dog)
{
	out << "Dog [" << dog.getType() << "]";
	return (out);
}