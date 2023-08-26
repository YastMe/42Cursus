/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:43:03 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 19:23:02 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called." << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called." << std::endl;
	_value = fixed.getRawBits();
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called." << std::endl;
	_value = value << _fBits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called." << std::endl;
	_value = roundf(value * (1 << _fBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called." << std::endl;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called." << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called." << std::endl;
	_value = raw;
}

Fixed & Fixed::operator = (const Fixed &fixed)
{
	//std::cout << "Copy assignment operator called." << std::endl;
	if (this != &fixed)
		_value = fixed.getRawBits();
	return (*this);
}

int	Fixed::toInt(void) const
{
	return (_value >> _fBits);
}

float	Fixed::toFloat(void) const
{
	return ((float) _value / (float) (1 << _fBits));
}

bool Fixed::operator > (const Fixed &fixed)
{
	return (_value > fixed.getRawBits());
}

bool Fixed::operator < (const Fixed &fixed)
{
	return (_value < fixed.getRawBits());
}

bool Fixed::operator >= (const Fixed &fixed)
{
	return (_value >= fixed.getRawBits());
}

bool Fixed::operator <= (const Fixed &fixed)
{
	return (_value <= fixed.getRawBits());
}

bool Fixed::operator == (const Fixed &fixed)
{
	return (_value == fixed.getRawBits());
}

bool Fixed::operator != (const Fixed &fixed)
{
	return (_value != fixed.getRawBits());
}

Fixed Fixed::operator + (const Fixed &fixed)
{
	return (Fixed(toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator - (const Fixed &fixed)
{
	return (Fixed(toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator * (const Fixed &fixed)
{
	return (Fixed(toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator / (const Fixed &fixed)
{
	return (Fixed(toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator - (void)
{
	return (Fixed(-toFloat()));
}

Fixed & Fixed::operator ++ (void)
{
	_value++;
	return (*this);
}

Fixed & Fixed::operator -- (void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator -- (int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed & Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed & Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed & Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed & Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
