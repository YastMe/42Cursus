/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:50:13 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 18:51:33 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		~Point(void);
		Point & operator = (const Point &point);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

std::ostream & operator << (std::ostream &out, const Point &point);

#endif