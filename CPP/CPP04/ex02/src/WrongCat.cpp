/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:08:24 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/30 13:20:51 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called on " << *this << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongcat): WrongAnimal(wrongcat._type)
{
	std::cout << "Copy constructor called on " << *this << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called on " << *this << std::endl;
}

WrongCat & WrongCat::operator = (const WrongCat &wrongcat)
{
	std::cout << "Copy operator called on " << *this << std::endl;
	if (&wrongcat != this)
		_type = wrongcat._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Niño tú qué quiere." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const WrongCat &wrongcat)
{
	out << "WrongCat [" << wrongcat.getType() << "]";
	return (out);
}