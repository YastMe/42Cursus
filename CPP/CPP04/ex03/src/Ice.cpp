/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:38:37 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:33:26 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Default constructor called on " << this << std::endl;
}

Ice::Ice(const Ice &ice)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_type = ice._type;
}

Ice::~Ice()
{
	std::cout << "Destructor called on " << this << std::endl;
}

Ice & Ice::operator = (const Ice &ice)
{
	std::cout << "Copy operator called on " << this << std::endl;
	if (this != &ice)
		_type = ice._type;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* Shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Ice &ice)
{
	out << "Ice [" << &ice << "]";
	return (out);
}