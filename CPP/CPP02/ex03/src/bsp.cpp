/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:50:03 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/24 19:17:00 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed abs(Fixed n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static Fixed area(Point vertexA, Point vertexB, Point vertexC)
{
	Fixed res;

	res = abs(vertexA.getX() * (vertexB.getY() - vertexC.getY())
		+ vertexB.getX() * (vertexC.getY() - vertexA.getY())
		+ vertexC.getX() * (vertexA.getY() - vertexB.getY()));
	return (res / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaBase(area(a, b, c));
	Fixed areaABP(area(a, b, point));
	Fixed areaACP(area(a, c, point));
	Fixed areaBCP(area(b, c, point));

	std::cout << "Area total: " << areaBase << std::endl;
	std::cout << "Area ABP: " << areaABP << std::endl;
	std::cout << "Area ACP: " << areaACP << std::endl;
	std::cout << "Area BCP: " << areaBCP << std::endl;

	return (areaBase == (areaABP + areaACP + areaBCP));
}
