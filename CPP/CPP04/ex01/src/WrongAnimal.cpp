/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:07:51 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:20:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "GenericWrongAnimal";
	std::cout << "Default constructor called on " << *this << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "Type constructor called on " << *this << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
	_type = wronganimal._type;
	std::cout << "Copy constructor called on " << *this << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called on " << *this << std::endl;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &wronganimal)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	if (&wronganimal != this)
		_type = wronganimal._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "Te me estás confundiendo de animal." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const WrongAnimal &wronganimal)
{
	out << "WrongAnimal [" << wronganimal.getType() << "]";
	return (out);
}