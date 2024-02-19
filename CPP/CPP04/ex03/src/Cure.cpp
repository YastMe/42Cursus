/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:38:40 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:23:16 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Default constructor called on " << this << std::endl;
}

Cure::Cure(const Cure &cure)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_type = cure._type;
}

Cure::~Cure()
{
	std::cout << "Destructor called on " << this << std::endl;
}

Cure & Cure::operator = (const Cure &cure)
{
	std::cout << "Copy operator called on " << this << std::endl;
	if (this != &cure)
		_type = cure._type;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* Cures " << target.getName() << "'s wounds *" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Cure &cure)
{
	out << "Cure [" << &cure << "]";
	return (out);
}