/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:50:10 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 19:22:06 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point()
{
	std::cout << "Default constructor called." << std::endl;
}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY())
{
	std::cout << "Copy constructor called." << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	std::cout << "Float constructor called." << std::endl;
}

Point::~Point()
{
	std::cout << "Destructor called." << std::endl;
}

Point & Point::operator = (const Point &point)
{
	std::cout << "Copy operator called." << std::endl;
	if (this != &point)
	{
		(Fixed) _x = point.getX();
		(Fixed) _y = point.getY();
	}
	return (*this);
}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return (out);
}
