/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:38:42 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/31 18:22:23 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor called on " << this << std::endl;
	_type = "Generic materia";
}

AMateria::AMateria(const AMateria &amateria)
{
	std::cout << "Copy constructor called on " << this << std::endl;
	_type = amateria._type;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "Type constructor called on " << this << std::endl;
	_type = type;
}

AMateria::~AMateria()
{
	std::cout << "Destructor called on " << this << std::endl;
}

AMateria & AMateria::operator = (const AMateria &amateria)
{
	std::cout << "Copy operator called on " << this << std::endl;
	if (this != &amateria)
		_type = amateria._type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (_type);
}

std::ostream &operator<<(std::ostream &out, const AMateria &amateria)
{
	out << "AMateria [" << amateria.getType() << "]";
	return (out);
}