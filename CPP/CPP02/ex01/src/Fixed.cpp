/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:43:03 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 17:35:14 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called." << std::endl;
	_value = fixed.getRawBits();
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called." << std::endl;
	_value = value << _fBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	_value = roundf(value * (1 << _fBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed & Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &fixed)
		_value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fBits);
}

float	Fixed::toFloat(void) const
{
	return ((float) _value / (float) (1 << _fBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
